
#include "Nivel2.h"
#include <string>
#include <stdio.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
using namespace std;
Nivel2::Nivel2() :vida1P(100), vida2P(100), respuesta1P(-1), respuesta2P(-1), listo1P(false), listo2P(false), ataca1P(false), ataca2P(false),empate(false),olvido(false)
{

}
bool run;
int a;
void Nivel2::Logica(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int currentMap)
{
   
    al_rest(0.2);
    a = 0;
    run = true;
    int randPreg;
    int posicion = 0;
    ALLEGRO_FONT* font2 = al_load_ttf_font("YARDSALE.ttf", 16, 0);
    ALLEGRO_BITMAP* reglas = al_load_bitmap("reglas_nivel2.jpg");
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_SAMPLE* song_empirista = NULL;
    ALLEGRO_SAMPLE* song_racionalista = NULL;
    ALLEGRO_SAMPLE_INSTANCE* songInstanceE = NULL;
    ALLEGRO_SAMPLE_INSTANCE* songInstanceR = NULL;

    background = al_load_bitmap("ring.jpg");
    al_clear_to_color(al_map_rgb(255, 255, 255));
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_install_keyboard(), "keyboard");
    al_register_event_source(queue, al_get_keyboard_event_source());

    //******Pantalla de reglas*******//
    al_draw_bitmap(reglas, 0, 0, 0);
    al_flip_display();

    while (true) {
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                break;
            }
        }
    }
    al_flush_event_queue(queue); //flush el queue para que no hallan inputs en cola
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_destroy_bitmap(reglas); //destroy bitmap para reducir el uso de memoria
    //******Fin de pantalla de reglas******//

    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_init_primitives_addon(), "primitives");
    must_init(al_install_audio(), "audio");
    must_init(al_init_acodec_addon(), "audio codec");
    al_register_event_source(queue, al_get_mouse_event_source());

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    al_register_event_source(queue, al_get_timer_event_source(timer));

    ALLEGRO_BITMAP* sprite1P = al_load_bitmap("1Psprite.png");
    ALLEGRO_BITMAP* sprite2P = al_load_bitmap("2Psprite.png");

    al_reserve_samples(5);
    song_empirista = al_load_sample("song_empirista.ogg");
    song_racionalista = al_load_sample("song_racionalista.ogg");

    songInstanceE = al_create_sample_instance(song_empirista);
    songInstanceR = al_create_sample_instance(song_racionalista);
    al_set_sample_instance_playmode(songInstanceE, ALLEGRO_PLAYMODE_ONCE);
    al_set_sample_instance_playmode(songInstanceR, ALLEGRO_PLAYMODE_ONCE);

    bool done = false;

    //al_draw_text(font2, al_map_rgb(0, 0, 0), 100, 100, 0, preguntas.escogerPregunta(cat,pos).c_str());
    al_start_timer(timer);

    //ANIMACION

    const int maxFrame = 9;
    int curFrame = 0;
    int frameCount = 0;
    int frameDelay = 5;

    ///ALLEGRO_BITMAP* sprite1[maxFrame];

    //sprite1[0] = al_load_bitmap("1Psprite.png");
    //sprite1[1] = al_load_bitmap("1Psprite.png");
    //sprite1[2] = al_load_bitmap("1Psprite.png");
    while (run) {
        if (posicion == 0) {
            randPreg = rand() % cantiPreguntas();
            posicion++;
        }

        al_draw_filled_rectangle(100, 50, 300, 100, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(110, 60, ((float)vida1P / 100) * (180) + 110, 90, al_map_rgb(0, 255, 0));
        al_draw_filled_rectangle(((float)vida1P / 100) * (180) + 110, 60, 290, 90, al_map_rgb(255, 0, 0));
        al_draw_filled_rectangle(500, 50, 700, 100, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(510, 60, ((float)vida2P / 100) * (180) + 510, 90, al_map_rgb(0, 255, 0));
        al_draw_filled_rectangle(((float)vida2P / 100) * (180) + 510, 60, 690, 90, al_map_rgb(255, 0, 0));
        if (a != 1)
            al_draw_multiline_text(font2, al_map_rgb(255, 255, 255), 210, 110, 550, 40, 0, buscarPregunta(randPreg).c_str());
        if (a == 1) {
            if (vida1P == 0) {
                ALLEGRO_BITMAP* nuevo = al_load_bitmap("ganado2.jpg");
                al_draw_bitmap(nuevo, 0, 0, 0);
                al_attach_sample_instance_to_mixer(songInstanceR, al_get_default_mixer());
                al_play_sample_instance(songInstanceR);
            }
            else if (vida2P == 0) {
                ALLEGRO_BITMAP* nuevo = al_load_bitmap("ganado1.jpg");
                al_draw_bitmap(nuevo, 0, 0, 0);
                al_attach_sample_instance_to_mixer(songInstanceE, al_get_default_mixer());
                al_play_sample_instance(songInstanceE);
            }

            switch (event.type) {
            case ALLEGRO_EVENT_KEY_DOWN:

                if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
                    if (vida1P == 0)
                        al_stop_sample_instance(songInstanceR);
                    else
                        al_stop_sample_instance(songInstanceE);

                    vida1P = 100;
                    vida2P = 100;
                    a = 0;
                    done = true;
                    run = false;
                }

                break;
            }

        }
        if (vida1P == 0) {
            a = 1;
        }
        else if (vida2P == 0) {
            a = 1;
        }
        
        if (listo1P)
        {
            al_draw_text(font, al_map_rgb(255, 0, 0), 100, 110, 0, "LISTO");
        }

        if (listo2P)
        {
            al_draw_text(font, al_map_rgb(255, 0, 0), 500, 110, 0, "LISTO");
        }
        //al_draw_text(font2, al_map_rgb(0, 0, 0), 100, 100, 0, preguntas.escogerPregunta(cat, pos).c_str());
        //botonVolver(font, color, background);
        al_flip_display();
        al_wait_for_event(queue, &event);

        if (a == 0) {
            switch (event.type)
            {
            case ALLEGRO_EVENT_KEY_DOWN:
                if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                    if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                        done = true;
                        break;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_1) {
                        if (!listo1P) {
                            respuesta1P = 0;
                            listo1P = true;
                        }
                        break;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_2) {
                        if (!listo1P) {
                            respuesta1P = 1;
                            listo1P = true;
                        }
                        break;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_3) {
                        if (!listo1P) {
                            respuesta1P = 2;
                            listo1P = true;
                        }
                        break;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_4) {
                        if (!listo1P) {
                            respuesta1P = 3;
                            listo1P = true;
                        }
                        break;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_7) {
                        if (!listo2P) {
                            respuesta2P = 0;
                            listo2P = true;
                        }
                        break;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_8) {
                        if (!listo2P) {
                            respuesta2P = 1;
                            listo2P = true;
                        }
                        break;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_9) {
                        if (!listo2P) {
                            respuesta2P = 2;
                            listo2P = true;
                        }
                        break;
                    }
                    else if (event.keyboard.keycode == ALLEGRO_KEY_0) {
                        if (!listo2P) {
                            respuesta2P = 3;
                            listo2P = true;
                        }
                        break;
                    }

                }
                break;

            case ALLEGRO_EVENT_TIMER:
                if (ataca1P || ataca2P||empate||olvido) {
                    if (++frameCount >= frameDelay)
                    {
                        if (++curFrame >= maxFrame) {
                            curFrame = 0;
                            if (ataca1P)
                                vida2P -= 20;

                            if (ataca2P)
                                vida1P -= 20;

                            olvido = false;
                            empate = false;
                            ataca1P = false;
                            ataca2P = false;
                        }
                        frameCount = 0;
                    }
                }
                break;
            }
        }

        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_draw_bitmap(background, 0, 0, 0);
        if (ataca1P)
        {
            //
            al_draw_text(font2, al_map_rgb(255, 0, 0),260, 0, 0, "Jugador 1, Respondio bien");
            switch (curFrame)
            {
            case 0:
                al_draw_bitmap_region(sprite1P, 300, 135, 100, 135, 100, 300, 0);
                break;
            case 1:
                al_draw_bitmap_region(sprite1P, 300, 135, 100, 135, 150, 300, 0);
                break;
            case 2:
                al_draw_bitmap_region(sprite1P, 300, 135, 100, 135, 180, 300, 0);
                break;
            case 3:
                al_draw_bitmap_region(sprite1P, 300, 135, 100, 135, 220, 300, 0);
                break;
            case 4:
                al_draw_bitmap_region(sprite1P, 450, 135, 100, 135, 250, 300, 0);
                break;
            case 5:
                al_draw_bitmap_region(sprite1P, 450, 135, 100, 135, 300, 300, 0);
                break;
            case 6:
                al_draw_bitmap_region(sprite1P, 450, 135, 100, 135, 350, 300, 0);
                break;
            case 7:
                al_draw_bitmap_region(sprite1P, 600, 135, 110, 135, 420, 300, 0);
                break;
            case 8:
                al_draw_bitmap_region(sprite1P, 600, 135, 110, 135, 420, 300, 0);
                break;
           
            }
        }
        else
        {
            al_draw_bitmap_region(sprite1P, 0, 135, 90, 271, 100, 300, 0);

        }

        if (ataca2P)
        {
            al_draw_text(font2, al_map_rgb(255, 0, 0), 260, 0, 0, "Jugador 2, Respondio bien");
            switch (curFrame)
            {
            case 0:
                al_draw_bitmap_region(sprite2P, 300, 135, 100, 135, 420, 300, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 1:
                al_draw_bitmap_region(sprite2P, 300, 135, 100, 135, 370, 300, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 2:
                al_draw_bitmap_region(sprite2P, 300, 135, 100, 135, 320, 300, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 3:
                al_draw_bitmap_region(sprite2P, 300, 135, 100, 135, 280, 300, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 4:
                al_draw_bitmap_region(sprite2P, 450, 135, 100, 135, 240, 300, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 5:
                al_draw_bitmap_region(sprite2P, 450, 135, 100, 135, 200, 300, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 6:
                al_draw_bitmap_region(sprite2P, 450, 135, 100, 135, 180, 300, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 7:
                al_draw_bitmap_region(sprite2P, 600, 135, 110, 135, 150, 300, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 8:
                al_draw_bitmap_region(sprite2P, 600, 135, 110, 135, 150, 300, ALLEGRO_FLIP_HORIZONTAL);
                break;
            }
        }
        else {
            al_draw_bitmap_region(sprite2P, 0, 135, 90, 271, 500, 300, ALLEGRO_FLIP_HORIZONTAL);
        }
        if (empate) {
            al_draw_text(font2, al_map_rgb(255, 0, 0), 260, 0, 0, "Ambos jugadores respondieron bien, es un empate");
           
        }
        if (olvido) {
            al_draw_text(font2, al_map_rgb(255, 0, 0), 260, 0, 0, "Ningun jugador respondio bien");
            
        }
       
        if (respuesta1P != -1 && respuesta2P != -1)
        {
            if (respuesta1P == obtenerRespuesta(randPreg) && respuesta2P != obtenerRespuesta(randPreg))
            {
                ataca1P = true;
            }
            else if (respuesta1P != obtenerRespuesta(randPreg) && respuesta2P == obtenerRespuesta(randPreg))
            {
                ataca2P = true;
            }
            else if (respuesta1P == obtenerRespuesta(randPreg) && respuesta2P == obtenerRespuesta(randPreg))
            {
                empate = true;
            }
            else if (respuesta1P != obtenerRespuesta(randPreg) && respuesta2P != obtenerRespuesta(randPreg))
            {
                olvido = true;
            }

            respuesta1P = -1;
            respuesta2P = -1;
            listo1P = false;
            
            listo2P = false;
            posicion = 0;
        }

        if (done) {
            al_destroy_sample(song_empirista);
            al_destroy_sample(song_racionalista);
            al_destroy_sample_instance(songInstanceE);
            al_destroy_sample_instance(songInstanceR);
            al_destroy_bitmap(sprite1P);
            al_destroy_bitmap(sprite2P);
            /*for (int i = 0;i < maxFrame;i++) {
                al_destroy_bitmap(sprite1[i]);
            }*/
            return;
        }
    }
}


void Nivel2::must_init(bool test, const char* description)
{
    if (test) return;
    printf("couldn't initialize %s\n", description);
    exit(1);
}
string Nivel2::buscarPregunta(int _codigo) {
    ifstream NivelIn("PreguntasNivel2/Nivel2.dat", ios::in);
    
    if (!NivelIn) {
        return "Error al intentar abrir el archivo.";
    }

    int codP;
    int p;
    char nombre[1000];
    string volver;
    while (NivelIn >> codP >> nombre >> p) {
        if (codP == _codigo)
        {
            for (int x = 0; x < 1000;x++) {
                if (nombre[x] == ' ') {
                    volver = nombre;
                    return volver;
                }
                if (nombre[x] == '-') {
                    nombre[x] = ' ';
                }
                else if (nombre[x] == '/') {
                    nombre[x] = '\n';
                }
            }
            volver = nombre;
            NivelIn.close();
            return volver;
        }
    }
    NivelIn.close();
    return "No logro entrar revisar el archivo de texto.";
}
int Nivel2::cantiPreguntas() {
    ifstream NivelIn("PreguntasNivel2/Nivel2.dat", ios::in);
   
    if (!NivelIn) {
        return -1;
    }

    int codP;
    int p;
    char nombre[1000];
    int total = 0;
    while (NivelIn >> codP >> nombre >> p) {
        total = total + 1;
    }
    NivelIn.close();
    return total;
}

int Nivel2::obtenerRespuesta(int _cod) {
    ifstream NivelIn("PreguntasNivel2/Nivel2.dat", ios::in);
   
    if (!NivelIn) {
        return -1;
    }

    int codP;
    int p;
    char nombre[1000];
    string volver;
    while (NivelIn >> codP >> nombre >> p) {
        if (codP == _cod)
        {
            NivelIn.close();
            return p;
        }
    }
    return -1;
}

