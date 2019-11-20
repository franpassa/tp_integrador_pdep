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

bajoCoste* inicializarTipoBajoCoste(char* zona);
estandar* inicializarTipoEstandar();
deLujo* inicializarTipoDeLujo(int visitas);
anfitrion* inicializarAnfitrion(char* nombre,int energia,float procesamiento,nodo_recuerdo* Recuerdos);
recuerdo* inicializarRecuerdo(char* descripcion, escenario* Escenario);
escenario* inicializarEscenario(char* nombre, void* categoria);

//Funciones para agregar elementos a las listas

nodo_anfitrion* agregarAnfitrionALista(anfitrion* Anfitrion, nodo_anfitrion* Lista);
nodo_recuerdo* agregarRecuerdoALista(recuerdo* Recuerdo, nodo_recuerdo* Lista);

//Funciones para mostrar

void mostrarListaAnfitriones(nodo_anfitrion* Lista);
void mostrarEscenario(escenario* Escenario);

//Funciones relacionadas al enunciado del parcial

float felicidadDeAnfitrion(anfitrion* Anfitrion);
float rebeldiaDeAnfitrion(anfitrion* Anfitrion);

int nivelDeFama(escenario* Escenario);
int emotividad(recuerdo* Recuerdo);

escenario* evolucionarEscenario(escenario* Escenario);

