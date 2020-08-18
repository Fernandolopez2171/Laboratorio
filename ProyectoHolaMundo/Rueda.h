#pragma once
#ifndef RUEDA_H
#define RUEDA_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
class Rueda {
private:
	float angulo, targetF;
	int vuetas;
	ALLEGRO_BITMAP* background;


public:
	Rueda(int);
	void Draw();
	void setTargetF(float);
	void Girar(float);
	void setAngulo(float);
	int random(int);
};

#endif // !RUEDA_H
