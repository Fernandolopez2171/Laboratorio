#pragma once
#ifndef NIVEL3_H
#define NIVEL3_H
#define SCREENW 800
#define SCREENH 450
#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <random>
#include <stdio.h>
#include <fstream>
using namespace std;

class Nivel3
{
public:
	Nivel3();
	bool Logica();

private:
	void must_init(bool, const char*);
	void jugar(bool);
	string buscarPregunta(int, bool);
	int cantiPreguntas(bool);
	int obtenerRespuesta(int, bool);
};
#endif // !NIVEL3_H