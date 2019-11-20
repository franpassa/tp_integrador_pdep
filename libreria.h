#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Estructuras*/

//Escenario

typedef struct escenario{
    char* nombre;
    char* categoria;
}escenario;

//Recuerdos

typedef struct recuerdo{
    char* descripcion;
    escenario Escenario;
}recuerdo;

typedef struct nodo_recuerdo{
    recuerdo Recuerdo;
    struct nodo_recuerdo* siguiente;
}nodo_recuerdo;

//Anfitriones

typedef struct anfitrion{
	char* nombre;
	int energia;
	float procesamiento;
	nodo_recuerdo* recuerdos;
}anfitrion;

typedef struct nodo_anfitrion{
	anfitrion anfitrion;
	struct nodo_anfitrion* siguiente;
}nodo_anfitrion;

/*Funciones*/
//Funciones para inicializar las estructuras

anfitrion* inicializarAnfitrion(char* nombre,int energia,float procesamiento,nodo_recuerdo* Recuerdos);
recuerdo* inicializarRecuerdo(char* descripcion, escenario Escenario);
escenario inicializarEscenario(char* nombre, char* categoria);

//Funciones para agregar elementos a las listas

nodo_anfitrion* agregarAnfitrionALista(anfitrion* Anfitrion, nodo_anfitrion* Lista);
nodo_recuerdo* agregarRecuerdoALista(recuerdo* Recuerdo, nodo_recuerdo* Lista);

//Funciones para mostrar

void mostrarListaAnfitriones(nodo_anfitrion* Lista);
