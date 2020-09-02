#pragma once
#ifndef NIVEL2_H
#define NIVEL2_H

#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <random>
#include <stdio.h>
using namespace std;

class Nivel2 {
public:
	Nivel2();
	void Logica(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int);
	
private:
	int vida1P, respuesta1P, vida2P, respuesta2P;
	bool listo1P, listo2P, ataca1P, ataca2P;
	string Preguntas[14];
	int respuestas[14];
	void must_init(bool, const char*);

};
#endif // !NIVEL2_H