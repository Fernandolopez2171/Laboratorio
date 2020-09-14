#pragma once
#ifndef PREGUNTAS_H
#define PREGUNTAS_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Preguntas {
public:
	Preguntas();

	string buscarPregunta(int, int);
	int cantiPreguntas(int);
	int obtenerRespuesta(int,int);
private:

};

#endif // !PREGUNTAS_H