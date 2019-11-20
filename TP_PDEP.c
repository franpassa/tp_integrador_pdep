#include "libreria.h"

int main() {
	deLujo* deLujo = inicializarTipoDeLujo(10);
	//estandar* estandar = inicializarTipoEstandar();
	//bajoCoste* BajoCoste = inicializarTipoBajoCoste("vicente lopez");
    escenario* cantina = inicializarEscenario("Cantina",deLujo);
    recuerdo* RecuerdoAmor = inicializarRecuerdo("Conocio al amor de su vida en la cantina",cantina);

    nodo_recuerdo* RecuerdosDeDolores = NULL;
    RecuerdosDeDolores = agregarRecuerdoALista(RecuerdoAmor,RecuerdosDeDolores);

	anfitrion* Dolores = inicializarAnfitrion("Dolores",90,0.7,RecuerdosDeDolores);

	nodo_anfitrion* Anfitriones = NULL;
	Anfitriones = agregarAnfitrionALista(Dolores,Anfitriones);
	mostrarListaAnfitriones(Anfitriones);

	printf("El nivel de felicidad de Dolores es: %.2f\n",felicidadDeAnfitrion(Dolores));
	printf("El nivel de rebeldia de Dolores es: %.4f\n",rebeldiaDeAnfitrion(Dolores));

	printf("El nivel de fama del escenario Cantina es: %d\n",nivelDeFama(cantina));
	printf("La emotividad del recuerdo de Dolores es: %d\n",emotividad(RecuerdoAmor));

	mostrarEscenario(cantina);
	evolucionarEscenario(cantina);
	mostrarEscenario(cantina);

	system("pause");
	return 0;
}
