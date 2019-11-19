#include "libreria.h"

int main() {
    escenario cantina = inicializarEscenario("Cantina","estandar");
    recuerdo* RecuerdoAmor = inicializarRecuerdo("Conocio al amor de su vida",cantina);

    nodo_recuerdo* RecuerdosDeDolores = NULL;
    RecuerdosDeDolores = agregarRecuerdoALista(RecuerdoAmor,RecuerdosDeDolores);

	anfitrion* Dolores = inicializarAnfitrion("Dolores",90,0.7,RecuerdosDeDolores);

	nodo_anfitrion* Anfitriones = NULL;
	Anfitriones = agregarAnfitrionALista(Dolores,Anfitriones);
	mostrarListaAnfitriones(Anfitriones);

	return 0;
}
