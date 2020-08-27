#pragma once
#ifndef MAPA_H
#define MAPA_H
#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>

using namespace std;

class Mapa {

private:

public:

	Mapa();
	//Botones
	void botonVolver(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background);
	//Pantalla
	bool estruMap(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background);
};

#endif // !MAPA_H