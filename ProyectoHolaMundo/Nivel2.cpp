#include "Nivel2.h"
#include <string>
#include <stdio.h>
using namespace std;
Nivel2::Nivel2() :vida1P(100), vida2P(100), respuesta1P(-1), respuesta2P(-1), listo1P(false), listo2P(false), ataca1P(false), ataca2P(false)
{
    Preguntas[0] = "Para Kant, cuales son los tres postulados de la razon practica:\nA. Dios, alma y mundo\nB. Vida, alma y salud\nC. Vida alma y mundo\nD. Dios, salud y mundo";
    Preguntas[1] = "Segun los empiristas, como se adquiere el conocimiento\nA. Idea innata\nB. Tabula rasa";
    Preguntas[2] = "Segun los racionalistas, como se adquiere el conocimiento:\nA. Idea innata\nB. Tabula rasa";
    Preguntas[3] = "Es un empirista:\nA. Francis Bacon\nB. Descartes\nC. Spiroza\nD. Leibniz";
    Preguntas[4] = "Es un racionalista: \nA. Francis Bacon\nB. D. Hume\nC. Descartes\nD. John Locke";
    Preguntas[5] = "Para descartes existen tres tipos de ideas: \nA.Innatas, adventicias y facticias\nB. Innatas, simples, complejas\nC. Primarias, adventicias, complejas\nD. Complejas, innatas y facticias";
    Preguntas[6] = "Kant distingue tres facultades de conocimiento:  \nA. Sensibilidad, Entendimiento y Razon\nB. Sensibilidad, Transcendencia y Poder\nC. Transcendecia, Entendimiento y Razon";
    Preguntas[7] = "De que campo proceden los racionalistas: \nA. Ciencias Naturales\nB. Matematicas";
    Preguntas[8] = "De que campo proceden los empiristas: \nA. Ciencias Naturales\nB. Matematicas";
    Preguntas[9] = "El metodo propio del racionalismo es: \nA. Deductivo\nB. Inductivo";
    Preguntas[10] = "El metodo propio del empirismo es:\nA. Deductivo\nB. Inductivo";
    Preguntas[11] = "Cual era la frase celebre de Kant:\nA. Dignate a saber.\nB. Aprende a saber\nC. Atrevete a saber\nD. Aprende a conocer";
    Preguntas[12] = "Quien fue el maestro fundamental del racionalismo? \nA. Descartes.\nB. Kant\nC. Bacon\nD. Spiroza";
    Preguntas[13] = "Quien fue el maestro fundamental del empirismo? \nA. Descartes.\nB. Leibniz\nC. Spiroza\nD. Ninguno de los anteriores";

    respuestas[0] = 0;
    respuestas[1] = 1;
    respuestas[2] = 0;
    respuestas[3] = 0;
    respuestas[4] = 2;
    respuestas[5] = 0;
    respuestas[6] = 0;
    respuestas[7] = 1;
    respuestas[8] = 0;
    respuestas[9] = 0;
    respuestas[10] = 1;
    respuestas[11] = 1;
    respuestas[12] = 0;
    respuestas[13] = 3;
}
bool run;
void Nivel2::Logica(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int currentMap)
{
    run = true;
    int randPreg;
    int posicion = 0;
    ALLEGRO_FONT* font2 = al_load_ttf_font("YARDSALE.ttf", 20, 0);
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE* queue;

    al_clear_to_color(al_map_rgb(255, 255, 255));
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    al_register_event_source(queue, al_get_timer_event_source(timer));

    ALLEGRO_BITMAP* sprite1P = al_load_bitmap("1Psprite.png");
    ALLEGRO_BITMAP* sprite2P = al_load_bitmap("2Psprite.png");

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


    int a = 0;
    while (run) {
        if (posicion == 0) {
            randPreg = rand() % 13;
            posicion++;
        }
        //al_draw_bitmap(background, 0, 0, 0);
        al_draw_filled_rectangle(100, 50, 300, 100, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(110, 60, ((float)vida1P / 100) * (180) + 110, 90, al_map_rgb(0, 255, 0));
        al_draw_filled_rectangle(((float)vida1P / 100) * (180) + 110, 60, 290, 90, al_map_rgb(255, 0, 0));
        al_draw_filled_rectangle(500, 50, 700, 100, al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(510, 60, ((float)vida2P / 100) * (180) + 510, 90, al_map_rgb(0, 255, 0));
        al_draw_filled_rectangle(((float)vida2P / 100) * (180) + 510, 60, 690, 90, al_map_rgb(255, 0, 0));
        if(a!=1)
            al_draw_multiline_text(font2, al_map_rgb(0, 0, 0), 210, 110, 550, 40, 0, Preguntas[randPreg].c_str());
        if (a == 1) {
            if(vida1P==0)
                al_draw_multiline_text(font2, al_map_rgb(0, 0, 0), 210, 110, 550, 40, 0, "Jugador 2 ha ganado!\nPresione la tecla espacio para pasar al siguiente nivel");
            else if (vida2P == 0) {
                al_draw_multiline_text(font2, al_map_rgb(0, 0, 0), 210, 110, 550, 40, 0, "Jugador 1 ha ganado!\nPresione la tecla espacio para pasar al siguiente nivel");
            }

            switch (event.type) {
            case ALLEGRO_EVENT_KEY_DOWN:

                if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
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
            if (ataca1P || ataca2P) {
                if (++frameCount >= frameDelay)
                {
                    if (++curFrame >= maxFrame) {
                        curFrame = 0;
                        if (ataca1P)
                            vida2P -= 20;

                        if (ataca2P)
                            vida1P -= 20;

                        ataca1P = false;
                        ataca2P = false;
                    }
                    frameCount = 0;
                }
            }
            break;
        }

        al_clear_to_color(al_map_rgb(255, 255, 255));

        if (ataca1P)
        {
            switch (curFrame)
            {
            case 0:
                al_draw_bitmap_region(sprite1P, 300, 135, 100, 135, 100, 200, 0);
                break;
            case 1:
                al_draw_bitmap_region(sprite1P, 300, 135, 100, 135, 150, 200, 0);
                break;
            case 2:
                al_draw_bitmap_region(sprite1P, 300, 135, 100, 135, 180, 200, 0);
                break;
            case 3:
                al_draw_bitmap_region(sprite1P, 300, 135, 100, 135, 220, 200, 0);
                break;
            case 4:
                al_draw_bitmap_region(sprite1P, 450, 135, 100, 135, 250, 200, 0);
                break;
            case 5:
                al_draw_bitmap_region(sprite1P, 450, 135, 100, 135, 300, 200, 0);
                break;
            case 6:
                al_draw_bitmap_region(sprite1P, 450, 135, 100, 135, 350, 200, 0);
                break;
            case 7:
                al_draw_bitmap_region(sprite1P, 600, 135, 110, 135, 420, 200, 0);
                break;
            case 8:
                al_draw_bitmap_region(sprite1P, 600, 135, 110, 135, 420, 200, 0);
                break;
            }
        }
        else
        {
            al_draw_bitmap_region(sprite1P, 0, 135, 90, 271, 100, 200, 0);

        }

        if (ataca2P)
        {
            switch (curFrame)
            {
            case 0:
                al_draw_bitmap_region(sprite2P, 300, 135, 100, 135, 420, 200, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 1:
                al_draw_bitmap_region(sprite2P, 300, 135, 100, 135, 370, 200, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 2:
                al_draw_bitmap_region(sprite2P, 300, 135, 100, 135, 320, 200, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 3:
                al_draw_bitmap_region(sprite2P, 300, 135, 100, 135, 280, 200, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 4:
                al_draw_bitmap_region(sprite2P, 450, 135, 100, 135, 240, 200, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 5:
                al_draw_bitmap_region(sprite2P, 450, 135, 100, 135, 200, 200, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 6:
                al_draw_bitmap_region(sprite2P, 450, 135, 100, 135, 180, 200, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 7:
                al_draw_bitmap_region(sprite2P, 600, 135, 110, 135, 150, 200, ALLEGRO_FLIP_HORIZONTAL);
                break;
            case 8:
                al_draw_bitmap_region(sprite2P, 600, 135, 110, 135, 150, 200, ALLEGRO_FLIP_HORIZONTAL);
                break;
            }
        }
        else {
            al_draw_bitmap_region(sprite2P, 0, 135, 90, 271, 500, 200, ALLEGRO_FLIP_HORIZONTAL);
        }

        if (respuesta1P != -1 && respuesta2P != -1)
        {
            if (respuesta1P == respuestas[randPreg] && respuesta2P != respuestas[randPreg])
            {
                ataca1P = true;
            }
            else if (respuesta1P != respuestas[randPreg] && respuesta2P == respuestas[randPreg])
            {
                ataca2P = true;
            }
            else if (respuesta1P == respuestas[randPreg] && respuesta2P == respuestas[randPreg])
            {

            }
            else if (respuesta1P != respuestas[randPreg] && respuesta2P != respuestas[randPreg])
            {

            }

            respuesta1P = -1;
            respuesta2P = -1;
            listo1P = false;
            listo2P = false;
            posicion=0;
        }

        if (done) {
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

