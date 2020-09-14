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
	int p;
	char nombre[1000];
	string volver;
	
	while (NivelIn>>codP>>nombre>>p) {
		if (codP == _codigo)
		{
			for (int x = 0; x < 1000;x++) {
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
	int p;
	char nombre[1000];
	int total=0;
	while (NivelIn >> codP >> nombre >> p) {
			total=total+1;
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
	int p;
	char nombre[1000];
	string volver;
	while (NivelIn >> codP >> nombre >> p) {
		if (codP==_cod)
		{
			NivelIn.close();
			return p;
		}
	}
	return -1;
}