#include "Preguntas.h"

Preguntas::Preguntas() {

}


string Preguntas::buscarPregunta(int categoria, int _codigo) {
	ifstream NivelIn;
	if (categoria == 0) {
		//Arte
		NivelIn.open("PreguntasNivel1/Arte.dat", ios::in);
	}
	else if (categoria==1) {
		//Politica
		NivelIn.open("PreguntasNivel1/Politica.dat", ios::in);
	}
	else if (categoria == 2) {
		//Ciencia
		NivelIn.open("PreguntasNivel1/Ciencia.dat", ios::in);
	}
	else if (categoria == 3) {
		//Historia
		 NivelIn.open("PreguntasNivel1/Historia.dat", ios::in);
	}

	if (!NivelIn) {
		return "Error al intentar abrir el archivo.";
	}

	int codP;
	int respuesta;
	char nombre[10000];
	char salto = ' ';
	string volver = "";
	string aux;
	while (NivelIn >> codP >> respuesta) {
		do
		{
			if (salto == '\n') {
				if (codP == _codigo + 1) {
					NivelIn.close();
					return volver;
				}
				else {
					volver = "";
					salto = ' ';
					break;
				}
			}
			NivelIn >> aux;
			if (strcmp(aux.c_str(), "1)") == 0)
			{
				volver += "\n" + aux + " ";
			}
			else if (strcmp(aux.c_str(), "2)") == 0)
			{
				volver += "\n" + aux + " ";
			}
			else if (strcmp(aux.c_str(), "3)") == 0)
			{
				volver += "\n" + aux + " ";
			}
			else if (strcmp(aux.c_str(), "4)") == 0)
			{
				volver += "\n" + aux + " ";
			}
			else
			{
				volver += aux + " ";
			}

		} while (NivelIn.get(salto));
		if (codP == _codigo + 1) {
			NivelIn.close();
			return volver;
		}
	}
	NivelIn.close();
	return "No logro entrar revisar el archivo de texto.";
}
int Preguntas::cantiPreguntas(int _cat) {
	ifstream NivelIn;
	if (_cat == 0) {
		//Arte
		NivelIn.open("PreguntasNivel1/Arte.dat", ios::in);
	}
	else if (_cat == 1) {
		//Politica
		NivelIn.open("PreguntasNivel1/Politica.dat", ios::in);
	}
	else if (_cat == 2) {
		//Ciencia
		NivelIn.open("PreguntasNivel1/Ciencia.dat", ios::in);
	}
	else if (_cat == 3) {
		//Historia
		NivelIn.open("PreguntasNivel1/Historia.dat", ios::in);
	}

	if (!NivelIn) {
		return -1;
	}

	int codP;
	int respuesta;
	int total = 0;
	char nombre[10000];
	char salto = ' ';
	string volver = "";
	string aux;
	while (NivelIn >> codP >> respuesta) {
		total++;
		do
		{
			if (salto == '\n') {
				{
					volver = "";
					salto = ' ';
					break;
				}
			}
			NivelIn >> aux;

			volver += aux + " ";

		} while (NivelIn.get(salto));
	}
	NivelIn.close();
	return total;
}

int Preguntas::obtenerRespuesta(int _cat,int _cod) {
	ifstream NivelIn;
	if (_cat == 0) {
		//Arte
		NivelIn.open("PreguntasNivel1/Arte.dat", ios::in);
	}
	else if (_cat == 1) {
		//Politica
		NivelIn.open("PreguntasNivel1/Politica.dat", ios::in);
	}
	else if (_cat == 2) {
		//Ciencia
		NivelIn.open("PreguntasNivel1/Ciencia.dat", ios::in);
	}
	else if (_cat == 3) {
		//Historia
		NivelIn.open("PreguntasNivel1/Historia.dat", ios::in);
	}

	if (!NivelIn) {
		return -1;
	}

	int codP;
	int respuesta;
	char nombre[10000];
	char salto = ' ';
	string volver = "";
	string aux;
	while (NivelIn >> codP >> respuesta) {
		do
		{
			if (salto == '\n') {
				if (codP == _cod + 1) {
					NivelIn.close();
					return (respuesta - 1);
				}
				else {
					volver = "";
					salto = ' ';
					break;
				}
			}
			NivelIn >> aux;

			volver += aux + " ";

		} while (NivelIn.get(salto));
	}
	NivelIn.close();
	return -1;
}