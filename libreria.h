#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

//Huespedes

typedef struct huesped huesped;
typedef struct nodo_huesped nodo_huesped;

struct huesped{
	char* nombre;
	int energia;
	int minutosRestantes;
	nodo_anfitrion* anfitriones;
	nodo_huesped* huespedes;
};

struct nodo_huesped{
	huesped huesped;
	nodo_huesped* siguiente;
};

//Tramas

typedef struct trama{
	nodo_huesped* huespedes;
	nodo_anfitrion* anfitriones;
	escenario* escenario;
}trama;

/*Funciones*/
//Funciones para inicializar las estructuras

bajoCoste* inicializarTipoBajoCoste(char*);
estandar* inicializarTipoEstandar();
deLujo* inicializarTipoDeLujo(int);
anfitrion* inicializarAnfitrion(char*, int, float, nodo_recuerdo*);
huesped* inicializarHuesped(char*, int, int, nodo_anfitrion*, nodo_huesped*);
recuerdo* inicializarRecuerdo(char*, escenario*);
escenario* inicializarEscenario(char*, void*);

//Funciones para agregar elementos a las listas

nodo_anfitrion* agregarAnfitrionALista(anfitrion*, nodo_anfitrion*);
nodo_huesped* agregarHuespedALista(huesped*, nodo_huesped*);
nodo_recuerdo* agregarRecuerdoALista(recuerdo*, nodo_recuerdo*);

//Funciones para mostrar

void mostrarAnfitriones(nodo_anfitrion*);
void mostrarAnfitrion(anfitrion*);
void mostrarHuesped(huesped*);
void mostrarEscenario(escenario*);
void mostrarRecuerdos(nodo_recuerdo*);

//Funciones relacionadas al enunciado del parcial

float felicidadDeAnfitrion(anfitrion*);
float rebeldiaDeAnfitrion(anfitrion*);
float mapearFelicidadAnfitriones(nodo_anfitrion*);
float mapearFelicidadHuespedes(nodo_huesped*);

int nivelDeFama(escenario*);
int emotividad(recuerdo*);
int felicidadDeHuesped(huesped*);
double rebeldiaHuesped(huesped*);

escenario* evolucionarEscenario(escenario*);
void conocerEscenarioAnfitrion(anfitrion*, escenario*);
void conocerEscenarioHuesped(huesped*, escenario*);

anfitrion anfitrionMasFeliz(nodo_anfitrion*);
huesped huespedMasFeliz(nodo_huesped*);
float complejidad(trama);
bool huespedEsRebelde(huesped*);
bool anfitrionEsRebelde(anfitrion*);
bool todosAnfitrionesRebeldes(nodo_anfitrion* Anfitriones);
bool todosHuespedesRebeldes(nodo_huesped*);
bool esPicante(trama);
void matarAnfitrionesRebeldes(nodo_anfitrion*);
void renovar(trama);

//Funciones de utilidad

char* strconcat(char*, char*);
float ini_felicidadAnfitrion(anfitrion);
float ini_felicidadHuesped(huesped);
