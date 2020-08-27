#pragma once
#ifndef PREGUNTAS_H
#define PREGUNTAS_H
#include <string>
using namespace std;

class Preguntas {
public:
	Preguntas();
	string escogerPregunta(int, int);
	int escogerRespuesta(int, int);

private:
	string bancoPreguntas[4][5];
	//string opciones[4][5];
	int respuesta[4][5];

};

#endif // !PREGUNTAS_H