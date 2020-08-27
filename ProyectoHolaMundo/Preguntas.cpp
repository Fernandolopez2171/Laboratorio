#include "Preguntas.h"

Preguntas::Preguntas() {
	bancoPreguntas[0][0] = "Uno de los siguientes personajes fue el encargado de pintar la capilla Sixtina: \n1) Miguel Angel. \n2) Donatello. \n3) Leonardo Da Vinci. \n4) Francis Bacon";
	bancoPreguntas[0][1] = "Genio del renacimiento que esculpio el Moises, el David y la Pieta: \n1) Miguel Angel Buonarroti. \n2) Leonardo Da Vinci. \n3) Rafael Sanzio. \n4) Galileo Galilei";
	bancoPreguntas[0][2] = "Durante el renacimiento el estilo artistico que impregno el arte, la filosofia, la pintura escritura fue el: \n1) El Gotico. \n2) El barroco. \n3) El clasicismo. \n4) Romanticismo";
	bancoPreguntas[0][3] = "Durante el renacimiento surge una nueva vision del hombre, que se vio reflejada en el arte, en la politica y en las ciencias sociales y humanas, a lo que se denomina: \n1) Antropocentrismo. \n2) Humanismo. \n3) Paradigma antropologico. \n4) Teocentrismo.";
	bancoPreguntas[0][4] = "Cuatro genios del renacimiento (Leonardo, Donatello, Rafael y Michelangelo) han sido llevados a la pantalla en los comics de : \n1) Las tortugas ninjas. \n2) Los caballeros del Zodiaco. \n3) Los cuatro fantasticos. \n4) Los antagonistas de Attack Titan";

	bancoPreguntas[1][0] = "Durante el renacimiento, el modelo de gobierno es uno de los siguientes: \n1) Monarquia absoluta. \n2) Tirania republicana. \n3) Democracia participativa. \n4) Liberalismo politico.";
	bancoPreguntas[1][1] = "De los siguientes acontecimientos, selecciones el que inicia el periodo moderno: \n1) Toma de Constantinopla. \n2) Tratado de paz de westfalia. \n3) Toma de la Bastilla. \n4) La ruta de la seda.";
	bancoPreguntas[1][2] = "Durante el siglo XV, la sociedad se estratifica en tres estamentos definidos: \n1) Clase media, baja y alta. \n2) nobleza, clero y estado llano. \n3) Artesanos, guardianes y gobernantes";
	bancoPreguntas[1][3] = "Aparece el realismo politico, que se basaba en un orden establecido, explicacion de un sistema y recomendaciones de como gobernar: \n1) Tomas Moro. \n2) Jean Bodin. \n3) Nicolas Maquiavelo. \n4) Erasmo de Rotterdam.";
	bancoPreguntas[1][4] = "Terminada la edad media, en el contexto de la politica resulta que: \n1) La Iglesia resalta su poder. \n2) La Iglesia pierde el papel rector en la politica. \n3) La Iglesia evangelica se posiciona en la politica.";

	bancoPreguntas[2][0] = "Entre los siguientes renacentistas seleccione, uno de los precursores filosofo-cientifico del heliocentrismo (teoria que afirma que el sol es el centro del universo): \n1) Tomas Moro. \n2) Galileo. \n3) Platon.";
	bancoPreguntas[2][1] = "El metodo cientifico se introduce por el interes de tres filosofos. Entre los siguientes uno de los mencionados no es precursor del metodo cientifico: \n1) Francis Bacon. \n2) Galileo Galilei. \n3)Nicolas Maquiavelo. \n4) Rene Descartes";
	bancoPreguntas[2][2] = "Es uno de los precursores del pensamiento Moderno: \n1) Isaac Newton. \n2) Rene Descartes. \n3) Erasmo de Roterdam";
	bancoPreguntas[2][3] = "De los siguientes filosofos niega el geocentrismo (teoria que afirma que el centro de nuestro sistema solar es la tierra): \n1) Aristoteles. \n2) Nicolas Copernico. \n3) Tomas de Aquino";
	bancoPreguntas[2][4] = "Uno de los inventos que suscito un conocimiento ilimitado, fue el de Gutenberg: \n1) El astrolabio. \n2) La imprenta. \n3) La Nao y la Carabela. \n4) El Telescopio";

	bancoPreguntas[3][0] = "Despues del feudalismo medieval acudimos al surgimiento de una nueva clase social conocida como la: \n1) La monarquia. \n2) El mercantilismo. \n3) La burguesia. \n4) El proletariado";
	bancoPreguntas[3][1] = "El renacimiento supone una epoca de absolutismo y nacionalismos, como el nacimiento de fuertes monarquias europeas centralizadas como: \n1) Grecia. \n2) Inglaterra. \n3) Yugoslavia. \n4) Egipto";
	bancoPreguntas[3][2] = "Antes de la consolidacion del estado moderno, Italia estuvo divida en pequenas ciudades-estado normalmente enfrentadas entre si, como es el caso de: \n1) Florencia-Napoli. \n2) Amsterdam-Cracovia. \n3) Reims-Colonia. \n4) Milan-Lourdes.";
	bancoPreguntas[3][3] = "La toma de Constantinopla supone un bloqueo comercial entre Europa y Asia (la ruta de la seda) y ocurrio en lo que hoy es actualmente: \n1) Eslovaquia. \n2) Estambul en Turquia. \n3) Mesopotamia";
	bancoPreguntas[3][4] = "Resurge el interes por Grecia y Roma, junto al declive del sistema feudal, el crecimiento del comercio e innovaciones entre las que mencionamos: \n1) La imprenta y la brujula. \n2) La rueda y la escritura \n3) Las maquinas de vapor y la produccion en masa,";

	respuesta[0][0] = 0;
	respuesta[0][1] = 0;
	respuesta[0][2] = 1;
	respuesta[0][3] = 1;
	respuesta[0][4] = 0;

	respuesta[1][0] = 0;
	respuesta[1][1] = 1;
	respuesta[1][2] = 1;
	respuesta[1][3] = 2;
	respuesta[1][4] = 1;

	respuesta[2][0] = 1;
	respuesta[2][1] = 2;
	respuesta[2][2] = 1;
	respuesta[2][3] = 1;
	respuesta[2][4] = 1;

	respuesta[3][0] = 2;
	respuesta[3][1] = 1;
	respuesta[3][2] = 0;
	respuesta[3][3] = 1;
	respuesta[3][4] = 0;

}

string Preguntas::escogerPregunta(int cat, int pos) {
	return bancoPreguntas[cat][pos];
}

int Preguntas::escogerRespuesta(int cat, int pos) {
	return respuesta[cat][pos];
}