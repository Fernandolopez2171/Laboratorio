#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_video.h>
#include "Rueda.h"
#include "Preguntas.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include <time.h>
#include <random>
#include <windows.h> 


using namespace std;
//variables globales
ALLEGRO_COLOR azul = al_map_rgba_f(0, 0, 0.5, 0.5);
ALLEGRO_COLOR rojo = al_map_rgba_f(0.5, 0, 0, 0.5);

ALLEGRO_EVENT event;
ALLEGRO_EVENT_QUEUE* queue;

//explicacion pendiente
int cargar;
bool preguntaRepetida[4][5];
//Declarar funciones
void cambioMap(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int);
bool entrarNivel1(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int);
bool entrarNivel2(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int);
bool entrarNivel3(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int);

bool displayPregunta(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int, int);

void must_init(bool test, const char* description)
{
    if (test) return;
    printf("couldn't initialize %s\n", description);
    exit(1);
}

//aqui cargamos el texto y el boton de salir 

void boton1(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Filosofia");
    al_draw_filled_rectangle(300, 350, 500, 400, color);
    al_draw_text(font, al_map_rgb(0, 0, 0), 340, 350, 0, "Salir");
    al_flip_display();
}

void boton2(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    al_draw_filled_rectangle(200, 300, 600, 250, color);
    al_draw_text(font, al_map_rgb(0, 0, 0), 250, 250, 0, "Puntuaciones");
    al_flip_display();
}

void boton3(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    al_draw_filled_rectangle(300, 200, 500, 135, color);
    al_draw_text(font, al_map_rgb(0, 0, 0), 340, 150, 0, "Mapa");
    al_flip_display();
}

//estructura boton volver de las pantallas
void botonVolver(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    al_draw_filled_rectangle(670, 0, 800, 60, color);
    al_draw_text(font, al_map_rgb(0, 0, 0), 675, 5, 0, "Salir");
    al_flip_display();
}
//Esctructura de la pantallas
bool estruPunt(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    //pantalla de puntuacion
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    bool done = false;
    //Cargar imagen y posicionar (Correr una vez)
    background = al_load_bitmap("puntuacion.jpeg");;
    al_draw_bitmap(background, 0, 0, 0);


    while (true) {
        color = azul;
        al_wait_for_event(queue, &event);
        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            //pasa por cierto rango cambia de color
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 60) {
                color = rojo;
                botonVolver(font, color, background);
            }
            else {
                color = azul;
                botonVolver(font, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            //al precionar el boton sale
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 100) {
                done = true;
                color = azul;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                //al precionar esc vuelve al inicio
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    //imprimir en pantalla para comprobar que se preciono la tecla

                    done = true;
                    color = azul;
                    break;
                }
            }
            break;
        }

        if (done) {
            cargar = 0;
            return true;
        }
    }
}
int puntos = 0;
string Puntos = "0";
const char* PuntosS = "0";
bool estruMap(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    Nivel2 nivel2;
    Nivel3 nivel3;
    int currentMap = 1;
    //pantalla de mapa
    //Registro de mouse y teclado
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    bool done = false;
    //Cargar imagen y posicionar (Correr una vez)
    //imagen temporal
    background = al_load_bitmap("mapa_reglas1.jpg");
    al_draw_bitmap(background, 0, 0, 0);
    // al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Mapa");
     //al_draw_filled_rectangle(150, 50, 170, 100, al_map_rgb(255, 0, 0));
    // al_draw_filled_triangle(140, 100, 180, 100, 160, 130, al_map_rgb(255, 0, 0));

     //bool refresh es para cargar el mapa nuevamente cuando se regresa de un nivel
    bool refresh = true;
    while (true) {
        //color = azul;
        if (refresh) {
            refresh = false;
            cambioMap(font, color, background, currentMap);
        }
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
            /*
            *  case ALLEGRO_EVENT_MOUSE_AXES:
            //pasa por cierto rango cambia de color
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 60) {
                color = rojo;
                botonVolver(font, color, background);
            }
            else {
                color = azul;
                botonVolver(font, color, background);
            }
            break;
            */


        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            //al precionar el boton sale
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 100) {
                done = true;
                color = azul;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                //al precionar esc vuelve al inicio
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    //imprimir en pantalla para comprobar que se preciono la tecla
                    done = true;
                    color = azul;
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                    if (currentMap == 1) {
                        currentMap = 2;
                    }
                    else if (currentMap == 2) {
                        currentMap = 3;
                    }
                    cambioMap(font, color, background, currentMap);
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                    if (currentMap == 3) {
                        currentMap = 2;

                    }
                    else if (currentMap == 2) {
                        currentMap = 1;
                    }
                    cambioMap(font, color, background, currentMap);
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                    if (currentMap == 1)
                    {
                        entrarNivel1(font, color, background, currentMap);
                    }
                    else if (currentMap == 2)
                    {
                        //if (puntos == 5) {
                           // entrarNivel2(font, color, background, currentMap);
                        /*}
                        else {
                            MessageBox(NULL, L"Lo sentimos no tiene suficientes puntos", L"Advertencia", MB_OK);
                        }*/
                        nivel2.Logica(font, color, background, currentMap);
                        al_flush_event_queue(queue);
                    }
                    else if (currentMap == 3)
                    {
                        nivel3.Logica();
                        al_flush_event_queue(queue);
                    }
                    refresh = true;
                }
            }
            break;
        }

        if (done) {
            cargar = 0;
            return true;
        }
    }
}

void cambioMap(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int currentMap) {
    //al_destroy_bitmap(background);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    background = al_load_bitmap("mapa_reglas1.jpg");
    al_draw_bitmap(background, 0, 0, 0);
    // al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Mapa");
    // botonVolver(font, color, background);

    if (currentMap == 1)
    {
        al_draw_filled_rectangle(150, 50, 170, 100, al_map_rgb(255, 0, 0));
        al_draw_filled_triangle(140, 100, 180, 100, 160, 130, al_map_rgb(255, 0, 0));
    }
    else if (currentMap == 2)
    {
        al_draw_filled_rectangle(390, 300, 410, 350, al_map_rgb(255, 0, 0));
        al_draw_filled_triangle(380, 350, 420, 350, 400, 380, al_map_rgb(255, 0, 0));
    }
    else if (currentMap == 3)
    {
        al_draw_filled_rectangle(550, 50, 570, 100, al_map_rgb(255, 0, 0));
        al_draw_filled_triangle(540, 100, 580, 100, 560, 130, al_map_rgb(255, 0, 0));
    }
    al_flip_display();
}

//Nivel 1, 2 y 3 temporal, copia de estruMap solo tiene el boton de regresar
//Variables puntos

bool entrarNivel1(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int currentMap) {
    Preguntas preguntas;
    al_clear_to_color(al_map_rgb(0, 0, 0));
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

    bool done = false;

    string pregunta = "";
    int respuesta = -1;
    int randCat;
    int randPreg;
    float targetCat;

    background = al_load_bitmap("fondo_ruleta.jpg");


    //botonVolver(font, color, background);
    Rueda rueda(0);

    al_start_timer(timer);
    while (true) {

        color = azul;
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background, 0, 0, 0);
        al_draw_text(font, al_map_rgb(255, 255, 255), 300, 0, 0, "Nivel 1");
        al_draw_text(font, al_map_rgb(255, 255, 255), 600, 0, 0, "PUNTOS");
        al_draw_text(font, al_map_rgb(255, 255, 255), 660, 60, 0, PuntosS);
        //botonVolver(font, color, background);
        rueda.Draw();
        al_draw_filled_triangle(230, 50, 270, 50, 250, 70, al_map_rgb(0, 0, 0));
        al_flip_display();
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            //pasa por cierto rango cambia de color
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 60) {
                color = rojo;
                //botonVolver(font, color, background);

            }
            else {
                color = azul;
                //botonVolver(font, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 100) {
                done = true;
                color = azul;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    done = true;
                    color = azul;
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_G) {
                    randCat = rand() % 4;
                    randPreg = rand() % preguntas.cantiPreguntas(randCat);
                    while (preguntaRepetida[randCat][randPreg]) {
                        randCat = rand() % 4;
                        randPreg = rand() % preguntas.cantiPreguntas(randCat);
                    }
                    preguntaRepetida[randCat][randPreg] = true;

                    if (randCat == 0)
                        targetCat = 5.10;
                    else if (randCat == 1)
                        targetCat = 3.5;
                    else if (randCat == 2)
                        targetCat = 1.9625;
                    else if (randCat == 3)
                        targetCat = 0.3925;

                    rueda.setTargetF(targetCat);
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_R) {
                    rueda.setTargetF(0);
                    rueda.setAngulo(0);
                    break;
                }

            }
            break;

        case ALLEGRO_EVENT_TIMER:
            break;
        }

        if (rueda.getFin()) {
            displayPregunta(font, color, background, randCat, randPreg);
            rueda.setTargetF(0);
            rueda.setAngulo(0);
        }

        if (done) {
            cargar = 0;
            return true;
        }
        if (puntos == 6)
        {
            background = al_load_bitmap("nivel1_gane.jpg");
            al_draw_bitmap(background, 0, 0, 0);
            al_flip_display();
            done = true;
            al_rest(2);
            break;
        }
    }
}


bool displayPregunta(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int cat, int pos) {
    Preguntas preguntas;
    ALLEGRO_FONT* font2 = al_load_ttf_font("YARDSALE.ttf", 18, 0);

    al_clear_to_color(al_map_rgb(0, 0, 0));
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

    bool done = false;

    string Categoria;

    switch (cat) {
    case 0:
        Categoria = "Arte";
        background = al_load_bitmap("arte.jpg");
        al_draw_bitmap(background, 0, 0, 0);
        break;
    case 1:
        Categoria = "Politica";
        background = al_load_bitmap("politica.jpg");
        al_draw_bitmap(background, 0, 0, 0);
        break;
    case 2:
        Categoria = "Ciencia";
        background = al_load_bitmap("ciencia.jpg");
        al_draw_bitmap(background, 0, 0, 0);
        break;
    case 3:
        Categoria = "Historia";
        background = al_load_bitmap("historia.jpg");
        al_draw_bitmap(background, 0, 0, 0);
        break;
    }

    int respuesta = -1;

    al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, Categoria.c_str());
    //al_draw_text(font2, al_map_rgb(0, 0, 0), 100, 100, 0, preguntas.escogerPregunta(cat,pos).c_str());
    al_draw_multiline_text(font2, al_map_rgb(0, 0, 0), 100, 100, 550, 40, 0, preguntas.buscarPregunta(cat, pos).c_str());
    al_start_timer(timer);


    while (true) {
        color = azul;
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background, 0, 0, 0);
        al_draw_text(font, al_map_rgb(255, 255, 255), 300, 0, 0, Categoria.c_str());
        //al_draw_text(font2, al_map_rgb(0, 0, 0), 100, 100, 0, preguntas.escogerPregunta(cat, pos).c_str());
        al_draw_multiline_text(font2, al_map_rgb(0, 0, 0), 100, 100, 550, 40, 0, preguntas.buscarPregunta(cat, pos).c_str());
        //botonVolver(font, color, background);
        al_flip_display();
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    done = true;
                    color = azul;
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_1) {
                    respuesta = 0;
                    if (preguntas.obtenerRespuesta(cat, pos) == respuesta) {
                        puntos = puntos + 1;
                        Puntos = to_string(puntos);
                        PuntosS = Puntos.c_str();
                        al_draw_text(font2, al_map_rgb(255, 0, 0), 190, 50, 0, "Asi me gusta lo has hecho muy bien");
                    }
                    else {
                        al_draw_text(font2, al_map_rgb(255, 0, 0), 190, 50, 0, "No te rindas, puede que el proximo intento funciones");
                    }
                    done = true;
                    al_flip_display();
                    break;

                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_2) {
                    respuesta = 1;
                    if (preguntas.obtenerRespuesta(cat, pos) == respuesta) {
                        puntos = puntos + 1;
                        Puntos = to_string(puntos);
                        PuntosS = Puntos.c_str();
                        al_draw_text(font2, al_map_rgb(255, 0, 0), 190, 50, 0, "Asi me gusta lo has hecho muy bien");
                    }
                    else {
                        al_draw_text(font2, al_map_rgb(255, 0, 0), 190, 50, 0, "No te rindas, puede que el proximo intento funciones");
                    }
                    done = true;
                    al_flip_display();
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_3) {
                    respuesta = 2;
                    if (preguntas.obtenerRespuesta(cat, pos) == respuesta) {
                        puntos = puntos + 1;
                        Puntos = to_string(puntos);
                        PuntosS = Puntos.c_str();
                        al_draw_text(font2, al_map_rgb(255, 0, 0), 190, 50, 0, "Asi me gusta lo has hecho muy bien");
                    }
                    else {
                        al_draw_text(font2, al_map_rgb(255, 0, 0), 190, 50, 0, "No te rindas, puede que el proximo intento funciones");
                    }
                    done = true;
                    al_flip_display();
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_4) {
                    respuesta = 3;
                    if (preguntas.obtenerRespuesta(cat, pos) == respuesta) {
                        puntos = puntos + 1;
                        Puntos = to_string(puntos);
                        PuntosS = Puntos.c_str();
                        al_draw_text(font2, al_map_rgb(255, 0, 0), 190, 50, 0, "Asi me gusta lo has hecho muy bien");
                    }
                    else {
                        al_draw_text(font2, al_map_rgb(255, 0, 0), 190, 50, 0, "No te rindas, puede que el proximo intento funciones");
                    }
                    done = true;
                    al_flip_display();
                    break;
                }

            }
            break;

        case ALLEGRO_EVENT_TIMER:
            break;
        }

        if (done) {
            al_rest(3);
            cargar = 0;
            return true;
        }
    }
}

bool entrarNivel3(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int currentMap) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    bool done = false;

    background = al_load_bitmap("nivel3.jpeg");;
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Nivel 3");
    botonVolver(font, color, background);
    while (true) {
        color = azul;

        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            //pasa por cierto rango cambia de color
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 60) {
                color = rojo;
                botonVolver(font, color, background);
            }
            else {
                color = azul;
                botonVolver(font, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 100) {
                done = true;
                color = azul;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    done = true;
                    color = azul;
                    break;
                }

            }
            break;
        }

        if (done) {
            cargar = 0;
            return true;
        }
    }
}

//Must init que atrapa cualquier error
int main()
{
    srand(time(0));
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            preguntaRepetida[i][j] = false;
        }
    }

    ALLEGRO_DISPLAY* display = al_create_display(800, 450);
    must_init(display, "display");

    ALLEGRO_FONT* font = al_load_ttf_font("YARDSALE.ttf", 64, 0);
    ALLEGRO_FONT* font2 = al_load_ttf_font("YARDSALE.ttf", 36, 0);
    ALLEGRO_FONT* font3 = al_load_ttf_font("YARDSALE.ttf", 18, 0);

    queue = al_create_event_queue();
    must_init(queue, "queue");

    must_init(al_init_image_addon(), "filo_background");

    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    al_register_event_source(queue, al_get_keyboard_event_source());
    must_init(al_init_primitives_addon(), "primitives");

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 25.0);
    al_register_event_source(queue, al_get_timer_event_source(timer));
    must_init(al_init_video_addon(), "video");
    ALLEGRO_VIDEO* intro = al_open_video("Intro.ogv");
    al_register_event_source(queue, al_get_video_event_source(intro));
    al_start_video(intro, al_get_default_mixer());

    bool redraw = true;
    bool use_frame_events = false;
    bool videoEnd = false;
    //al_set_video_playing(intro, !al_is_video_playing(intro));
    al_start_timer(timer);
    ALLEGRO_BITMAP* frame = al_create_bitmap(al_get_video_scaled_width(intro), al_get_video_scaled_height(intro));
    while (true)
    {

        frame = al_get_video_frame(intro);
        if (frame)
            al_draw_scaled_bitmap(frame, 0, 0, 1280, 720, 0, 0, 800, 450, 0);
        else
            cout << "Null";

        al_draw_text(font3, al_map_rgb(255, 255, 255), 0, 0, 0, "Presiona Esc para saltar");
        al_wait_for_event(queue, &event);
        switch (event.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
            switch (event.keyboard.keycode) {
            case ALLEGRO_KEY_SPACE:

                //al_set_video_playing(intro, !al_is_video_playing(intro));
                break;
            case ALLEGRO_KEY_ESCAPE:
                al_close_video(intro);
                videoEnd = true;
                break;
            default:
                break;
            }
            break;

        case ALLEGRO_EVENT_TIMER:
            /*
            display_time += 1.0 / 60;
            if (display_time >= video_time) {
               video_time = display_time + video_refresh_timer(is);
            }*/
            /*if (!use_frame_events) {
                redraw = true;
            }*/
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            al_close_video(intro);
            break;

        case ALLEGRO_EVENT_VIDEO_FRAME_SHOW:
            if (use_frame_events) {
                redraw = true;
            }
            break;

        case ALLEGRO_EVENT_VIDEO_FINISHED:
            videoEnd = true;
            break;
        default:
            break;
        }
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
        if (videoEnd)
            break;
    }

    ALLEGRO_BITMAP* background = al_load_bitmap("castillo1.jpg");
    if (!background)
    {
        printf("No se cargo el background\n");
        return 1;
    }

    al_register_event_source(queue, al_get_mouse_event_source());

    bool done = false;

    cargar = 0;

    while (true) {
        if (cargar == 0) {
            cargar = 1;
            //Correr una vez
            al_clear_to_color(al_map_rgb(255, 255, 255));

            al_draw_bitmap(background, 0, 0, 0);
            al_draw_text(font2, al_map_rgb(0, 0, 0), 300, 0, 0, "Filosofia");

            al_draw_filled_rectangle(300, 200, 500, 135, azul);
            al_draw_text(font2, al_map_rgb(0, 0, 0), 340, 150, 0, "Mapa");
            al_flip_display();

            al_draw_filled_rectangle(200, 300, 600, 250, azul);
            al_draw_text(font2, al_map_rgb(0, 0, 0), 250, 250, 0, "Puntuaciones");
            al_flip_display();

            al_draw_filled_rectangle(300, 350, 500, 400, azul);
            al_draw_text(font2, al_map_rgb(0, 0, 0), 340, 350, 0, "Salir");
            al_flip_display();
        }
        ALLEGRO_COLOR color = azul;
        al_wait_for_event(queue, &event);
        //Rango de cambio de colores para salir
        bool over_salir = event.mouse.x > 300 && event.mouse.x < 500 && event.mouse.y>350 && event.mouse.y < 400;
        //Rango de cambio de colores para puntuaciones
        bool over_points = event.mouse.x > 200 && event.mouse.x < 600 && event.mouse.y>250 && event.mouse.y < 300;
        //Rango de cambio de colores para mapa
        bool over_map = event.mouse.x > 300 && event.mouse.x < 500 && event.mouse.y>100 && event.mouse.y < 200;

        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (over_salir) {
                done = true;
                color = azul;
                boton1(font2, color, background);
            }
            else if (over_points) {
                color = azul;
                boton2(font2, color, background);
                //pantalla puntuacion
                estruPunt(font2, color, background);
            }
            else if (over_map) {
                color = azul;
                boton3(font2, color, background);
                //pantalla mapa
                estruMap(font2, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_AXES:
            if (event.mouse.x > 300 && event.mouse.x < 500 && event.mouse.y>350 && event.mouse.y < 400) {
                color = rojo;
                boton1(font2, color, background);

                color = azul;
                boton2(font2, color, background);
                boton3(font2, color, background);

            }
            else if (over_points)
            {
                color = rojo;
                boton2(font2, color, background);

                color = azul;
                boton1(font2, color, background);
                boton3(font2, color, background);

            }
            else if (over_map) {
                color = rojo;
                boton3(font2, color, background);
                color = azul;
                boton1(font2, color, background);
                boton2(font2, color, background);
            }

            else {
                color = azul;
                boton1(font2, color, background);
                boton2(font2, color, background);
                boton3(font2, color, background);
            }
            break;
        }

        if (done)
            break;

    }

    al_destroy_bitmap(background);
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_font(font);
    al_destroy_font(font2);

    return 0;
}