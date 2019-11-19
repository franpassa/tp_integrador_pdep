/*Estructuras*/

//Escenario

typedef struct{
    char* nombre;
    char* categoria;
}escenario;

//Recuerdos

typedef struct{
    char* descripcion;
    escenario Escenario;
}recuerdo;

typedef struct{
    recuerdo Recuerdo;
    struct nodo_recuerdo* siguiente;
}nodo_recuerdo;

//Anfitriones

typedef struct{
	char* nombre;
	int energia;
	float procesamiento;
	nodo_recuerdo* recuerdos;
}anfitrion;

typedef struct{
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
