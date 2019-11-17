#include "libreria.h"

int main() {
	anfitrion* Dolores = inicializarAnfitrion("Dolores",90,0.7,"mati te amo");
	nodo_anfitrion* Anfitriones = NULL;

	Anfitriones = agregarAnfitrionALista(Dolores,Anfitriones);
	mostrarListaAnfitriones(Anfitriones);


	return 0;
}
