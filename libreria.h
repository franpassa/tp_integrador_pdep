#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char* nombre;
	int energia;
	float procesamiento;
	char* recuerdo;
}anfitrion;

typedef struct{
	anfitrion anfitrion;
	struct Nodo_Anfitrion* siguiente;
}nodo_anfitrion;

typedef struct{
	int energia;
	int minutosRestantes;
	nodo_anfitrion* listaAnfitriones;
}huesped;

nodo_anfitrion* agregarAnfitrionALista(anfitrion* Anfitrion, nodo_anfitrion* Lista);
void mostrarListaAnfitriones(nodo_anfitrion* Lista);
anfitrion* inicializarAnfitrion(char* nombre,int energia,float procesamiento,char* recuerdo);

anfitrion* inicializarAnfitrion(char* nombre,int energia,float procesamiento,char* recuerdo){
	anfitrion* nuevoAnfitrion = malloc(sizeof(anfitrion));
	nuevoAnfitrion->nombre = strdup(nombre);
	nuevoAnfitrion->energia = energia;
	nuevoAnfitrion->procesamiento = procesamiento;
	nuevoAnfitrion->recuerdo = strdup(recuerdo);
	return nuevoAnfitrion;
}

nodo_anfitrion* agregarAnfitrionALista(anfitrion* Anfitrion, nodo_anfitrion* Lista)
{
    nodo_anfitrion* nuevoNodo = (nodo_anfitrion*)malloc(sizeof(nodo_anfitrion));
    nuevoNodo->anfitrion = *Anfitrion;
    nuevoNodo->siguiente = Lista;
    return nuevoNodo;
}

void mostrarListaAnfitriones(nodo_anfitrion* Lista){

	while(Lista!=NULL){
		printf("Nombre: %s\n",Lista->anfitrion.nombre);
		printf("Energia: %d\n",Lista->anfitrion.energia);
		printf("Procesamiento: %f\n",Lista->anfitrion.procesamiento);
		printf("Recuerdo: %s\n\n",Lista->anfitrion.recuerdo);
		Lista = Lista->siguiente;
	}
}
