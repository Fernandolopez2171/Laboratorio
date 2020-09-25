#include "Nivel3.h"
#include <string>
#include <stdio.h>
Nivel3::Nivel3()
{

}

void Nivel3::must_init(bool test, const char* description)
{
    if (test) return;
    printf("couldn't initialize %s\n", description);
    exit(1);
}

bool Nivel3::Logica()
{
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_BITMAP* fondo;
    ALLEGRO_FONT* font = al_load_ttf_font("YARDSALE.ttf", 64, 0);
    ALLEGRO_FONT* font2 = al_load_ttf_font("YARDSALE.ttf", 36, 0);
    ALLEGRO_FONT* font3 = al_load_ttf_font("YARDSALE.ttf", 20, 0);
    ALLEGRO_COLOR azul = al_map_rgb(0, 0, 130);
    ALLEGRO_COLOR azulHover = al_map_rgb(0, 0, 255);
    ALLEGRO_COLOR color1 = azul, color2 = azul;

    al_clear_to_color(al_map_rgb(0, 0, 0));
    queue = al_create_event_queue();
    must_init(queue, "queue");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    al_register_event_source(queue, al_get_timer_event_source(timer));

    fondo = al_load_bitmap("entrada.jpg");
    al_draw_bitmap(fondo, 0, 0, 0);

    bool done = false;
    al_start_timer(timer);
    while (true) {


        //al_clear_to_color(al_map_rgb(255, 0, 0));
        al_draw_filled_rectangle(200, 200, 350, 250, color1);
        al_draw_filled_rectangle(SCREENW - 200, 200, SCREENW - 350, 250, color2);
        al_draw_text(font3, al_map_rgb(255, 255, 255), 250, 210, 0, "Kant");
        al_draw_text(font3, al_map_rgb(255, 255, 255), 465, 210, 0, "Descartes");

        al_flip_display();
        al_wait_for_event(queue, &event);
        bool hoverBoton1 = (event.mouse.x >= 200 && event.mouse.x < 350 && event.mouse.y < 250 && event.mouse.y>200);
        bool hoverBoton2 = (event.mouse.x <= SCREENW - 200 && event.mouse.x > SCREENW - 350 && event.mouse.y < 250 && event.mouse.y>200);
        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            if (hoverBoton1)
                color1 = azulHover;
            else
                color1 = azul;

            if (hoverBoton2)
                color2 = azulHover;
            else
                color2 = azul;

            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (hoverBoton1)
            {
                jugar(true);
                jugar(false);
                al_flush_event_queue(queue);
                done = true;
            }
            else if (hoverBoton2)
            {
                jugar(false);
                jugar(true);
                al_flush_event_queue(queue);
                done = true;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    done = true;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_G) {


                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_R) {

                }

            }
            break;

        case ALLEGRO_EVENT_TIMER:
            break;
        }

        if (done) {

            break;
        }

    }

    al_destroy_font(font);
    al_destroy_font(font2);
    return true;
}

string Nivel3::buscarPregunta(int _codigo, bool kant) {

    ifstream NivelIn;

    if (kant)
        NivelIn.open("PreguntasNivel3/Nivel3-kant.dat", ios::in);
    else
        NivelIn.open("PreguntasNivel3/Nivel3-descartes.dat", ios::in);



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
            for (int x = 0; x < 1000; x++) {
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

int Nivel3::cantiPreguntas(bool kant) {
    string path;

    if (kant)
        path = "PreguntasNivel3/Nivel3-kant.dat";
    else
        path = "PreguntasNivel3/Nivel3-descartes.dat";

    ifstream NivelIn(path.c_str(), ios::in);

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

int Nivel3::obtenerRespuesta(int _cod, bool kant) {
    ifstream NivelIn;

    if (kant)
        NivelIn.open("PreguntasNivel3/Nivel3-kant.dat", ios::in);
    else
        NivelIn.open("PreguntasNivel3/Nivel3-descartes.dat", ios::in);

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

void Nivel3::jugar(bool kant)
{
    ALLEGRO_EVENT event;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_BITMAP* fondo = nullptr;
    ALLEGRO_BITMAP* fondo2 = al_load_bitmap("pasillo.jpg");
    ALLEGRO_FONT* font2 = al_load_ttf_font("YARDSALE.ttf", 16, 0);
    ALLEGRO_FONT* font3 = al_load_ttf_font("YARDSALE.ttf", 34, 0);


    al_clear_to_color(al_map_rgb(0, 0, 0));
    queue = al_create_event_queue();
    must_init(queue, "queue");
    al_register_event_source(queue, al_get_keyboard_event_source());
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    al_register_event_source(queue, al_get_timer_event_source(timer));

    if (kant)
    {
        fondo = al_load_bitmap("clase.jpg");

    }
    else
    {
        fondo = al_load_bitmap("lab.jpg");
        //al_draw_bitmap(fondo, 0, 0, 0);
    }


    bool done = false;
    bool respuesta = false;
    int pregunta = 0;
    al_start_timer(timer);

    while (true) {


        //al_draw_bitmap(fondo, 0, 0, 0);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(fondo, 0, 0, 0);
        // al_draw_filled_rectangle(200, 200, 350, 250, al_map_rgb(0, 0, 0));
         //al_draw_text(font, al_map_rgb(255, 255, 255), 660, 60, 0, "");
        al_draw_multiline_text(font2, al_map_rgb(255, 255, 255), 140, 100, 550, 40, 0, buscarPregunta(pregunta, kant).c_str());

        al_wait_for_event(queue, &event);
        switch (event.type)
        {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    done = true;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_1) {

                    if (obtenerRespuesta(pregunta, kant) == 0) {
                        //fondo2 = al_load_bitmap("pasillo.jpeg");
                        al_draw_bitmap(fondo2, 0, 0, 0);
                        //al_clear_to_color(al_map_rgb(0, 255, 0));
                        al_draw_text(font3, al_map_rgb(255, 255, 0), 40, 90, 0, "Asi me gusta lo has hecho muy bien");
                    }
                    else {
                        //al_clear_to_color(al_map_rgb(255, 0, 0));
                        //fondo2 = al_load_bitmap("pasillo.jpeg");
                        al_draw_bitmap(fondo2, 0, 0, 0);
                        al_draw_text(font3, al_map_rgb(255, 255, 0), 220, 90, 0, "No te rindas");
                    }
                    pregunta++;
                    respuesta = true;
                    break;

                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_2) {
                    if (obtenerRespuesta(pregunta, kant) == 1) {
                        //al_clear_to_color(al_map_rgb(0, 255, 0));
                        //fondo2 = al_load_bitmap("pasillo.jpeg");
                        al_draw_bitmap(fondo2, 0, 0, 0);
                        al_draw_text(font3, al_map_rgb(255, 255, 0), 40, 90, 0, "Asi me gusta lo has hecho muy bien");
                    }
                    else {
                        // al_clear_to_color(al_map_rgb(255, 0, 0));
                         //fondo2 = al_load_bitmap("pasillo.jpeg");
                        al_draw_bitmap(fondo2, 0, 0, 0);
                        al_draw_text(font3, al_map_rgb(255, 255, 0), 220, 90, 0, "No te rindas");
                    }
                    pregunta++;
                    respuesta = true;
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_3) {
                    if (obtenerRespuesta(pregunta, kant) == 2) {
                        //al_clear_to_color(al_map_rgb(0, 255, 0));
                        //fondo2 = al_load_bitmap("pasillo.jpeg");
                        al_draw_bitmap(fondo2, 0, 0, 0);
                        al_draw_text(font3, al_map_rgb(255, 255, 0), 40, 90, 0, "Asi me gusta lo has hecho muy bien");
                    }
                    else {
                        //al_clear_to_color(al_map_rgb(255, 0, 0));
                        //fondo2 = al_load_bitmap("pasillo.jpeg");
                        al_draw_bitmap(fondo2, 0, 0, 0);
                        al_draw_text(font3, al_map_rgb(255, 255, 0), 220, 90, 0, "No te rindas");
                    }
                    pregunta++;
                    respuesta = true;
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_4) {
                    if (obtenerRespuesta(pregunta, kant) == 3) {
                        // al_clear_to_color(al_map_rgb(0, 255, 0));
                         //fondo2 = al_load_bitmap("pasillo.jpeg");
                        al_draw_bitmap(fondo2, 0, 0, 0);
                        al_draw_text(font3, al_map_rgb(255, 255, 0), 40, 90, 0, "Asi me gusta lo has hecho muy bien");
                    }
                    else {
                        //al_clear_to_color(al_map_rgb(255, 0, 0));

                        al_draw_bitmap(fondo2, 0, 0, 0);
                        al_draw_text(font3, al_map_rgb(255, 255, 0), 220, 90, 0, "No te rindas");
                    }
                    pregunta++;
                    respuesta = true;
                }

                break;


            }
        case ALLEGRO_EVENT_TIMER:
            break;

        }

        if (respuesta)
        {
            al_flip_display();
            al_rest(1);
            respuesta = false;
        }
        else
        {
            al_flip_display();
        }

        if (done || pregunta > 4) {

            break;
        }

    }
    al_clear_to_color(al_map_rgb(255, 0, 0));
    fondo2 = al_load_bitmap("felicidades.png");
    al_draw_bitmap(fondo2, 0, 0, 0);
    al_flip_display();
    al_rest(1);
    al_destroy_font(font2);
}