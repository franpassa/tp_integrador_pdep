#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Estructuras*/
//Tipos de escenario

typedef struct bajoCoste{
	char* nombre;
	char* zona;
}bajoCoste;

typedef struct estandar{
	char* nombre;
}estandar;

typedef struct deLujo{
	char* nombre;
	int visitas;
}deLujo;

//Escenario

typedef struct escenario{
    char* nombre;
    void* categoria;
}escenario;

//Recuerdos

typedef struct recuerdo{
    char* descripcion;
    escenario* Escenario;
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

bajoCoste* inicializarTipoBajoCoste(char*);
estandar* inicializarTipoEstandar();
deLujo* inicializarTipoDeLujo(int);
anfitrion* inicializarAnfitrion(char*, int, float, nodo_recuerdo*);
recuerdo* inicializarRecuerdo(char*, escenario*);
escenario* inicializarEscenario(char*, void*);

//Funciones para agregar elementos a las listas

nodo_anfitrion* agregarAnfitrionALista(anfitrion*, nodo_anfitrion*);
nodo_recuerdo* agregarRecuerdoALista(recuerdo*, nodo_recuerdo*);

//Funciones para mostrar

void mostrarAnfitriones(nodo_anfitrion*);
void mostrarEscenario(escenario*);
void mostrarRecuerdos(nodo_recuerdo*);

//Funciones relacionadas al enunciado del parcial

float felicidadDeAnfitrion(anfitrion*);
float rebeldiaDeAnfitrion(anfitrion*);

int nivelDeFama(escenario*);
int emotividad(recuerdo*);

escenario* evolucionarEscenario(escenario*);
void conocer(anfitrion*, escenario*);

//Funciones de utilidad

char* strconcat(char*, char*);
