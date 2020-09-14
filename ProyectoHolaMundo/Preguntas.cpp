#include "Preguntas.h"

Preguntas::Preguntas() {

}


string Preguntas::buscarPregunta(int categoria, int _codigo) {
	ifstream clientesIn("Nivel1.dat", ios::in);

	if (!clientesIn) {
		return "Error al intentar abrir el archivo.";
	}


	int codP;
	int Cat;
	int p;
	char nombre[1000];
	string volver;
	
	while (clientesIn>>Cat>>codP>>nombre>>p) {
		if (Cat==categoria && codP == _codigo)
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
			clientesIn.close();
			return volver;
		}
	}
	clientesIn.close();
	return "No logro entrar revisar el archivo de texto.";
}
int Preguntas::cantiPreguntas(int _cat) {
	ifstream NivelIn("Nivel1.dat", ios::in);

	if (!NivelIn) {
		return -1;
	}

	int codP;
	int Cat;
	int p;
	char nombre[1000];
	int total=0;
	while (NivelIn >> Cat >> codP >> nombre >> p) {
		if (Cat == _cat )
		{
			total=total+1;
		}
	}
	NivelIn.close();
	return total;
}

int Preguntas::obtenerRespuesta(int _cat,int _cod) {
	ifstream NivelIn("Nivel1.dat", ios::in);

	if (!NivelIn) {
		return -1;
	}

	int codP;
	int Cat;
	int p;
	char nombre[1000];
	string volver;
	while (NivelIn >> Cat >> codP >> nombre >> p) {
		if (Cat == _cat && codP==_cod)
		{
			NivelIn.close();
			return p;
		}
	}
	return -1;
}