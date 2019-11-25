#include "libreria.h"

int main() {

	printf("--------Parte A--------\n\n");
	printf("Anfitriones: \n\n");
	//deLujo* deLujo = inicializarTipoDeLujo(10);
	//estandar* estandar = inicializarTipoEstandar();
	bajoCoste* BajoCoste = inicializarTipoBajoCoste("vicente lopez");
    escenario* cantina = inicializarEscenario("Cantina",BajoCoste);
    recuerdo* RecuerdoAmor = inicializarRecuerdo("Conocio al amor de su vida en la cantina",cantina);

    nodo_recuerdo* recuerdosDeDolores = NULL;
    recuerdosDeDolores = agregarRecuerdoALista(RecuerdoAmor,recuerdosDeDolores);

	anfitrion* Dolores = inicializarAnfitrion("Dolores",90,0.8,recuerdosDeDolores);

	nodo_anfitrion* Anfitriones = NULL;
	Anfitriones = agregarAnfitrionALista(Dolores,Anfitriones);
	mostrarAnfitriones(Anfitriones);
	huesped* William = inicializarHuesped("William",10,30,Anfitriones,NULL);

	printf("Huespedes: \n\n");
	mostrarHuesped(William);

	printf("\nEl nivel de felicidad de Dolores es: %.2f\n",felicidadDeAnfitrion(Dolores));
	int felicidad = felicidadDeHuesped(William);
	printf("El nivel de felicidad de William es: %d\n", felicidad);
	printf("El nivel de rebeldia de Dolores es: %.4f\n",rebeldiaDeAnfitrion(Dolores));
	double rebeldia = rebeldiaHuesped(William);
	printf("La rebeldia de William es: %.10lf\n", rebeldia);
	printf("La emotividad del recuerdo de Dolores es: %d\n\n",emotividad(RecuerdoAmor));

	printf("--------Parte B--------\n\n");
	printf("Escenarios:\n\n");

	mostrarEscenario(cantina);
	printf("\nEl nivel de fama del escenario Cantina es: %d\n\n", nivelDeFama(cantina));

	printf("Al evolucionarlo, la categoria cambia: \n\n");
	cantina = evolucionarEscenario(cantina);

	mostrarEscenario(cantina);

	printf("\nCuando William conoce el escenario Cantina queda de la siguiente manera: \n\n");
	conocerEscenarioHuesped(William,cantina);
	mostrarHuesped(William);

	printf("\n--------Parte C--------\n\n");

	nodo_huesped* Huespedes = NULL;
	Huespedes = agregarHuespedALista(William,Huespedes);

	trama Trama;
	Trama.anfitriones = Anfitriones;
	Trama.huespedes = Huespedes;
	Trama.escenario = cantina;

	printf("Trama: \n\n");

	printf("Anfitriones de la trama: %s\n",Trama.anfitriones->anfitrion.nombre);
	printf("Huespedes de la trama: %s\n",Trama.huespedes->huesped.nombre);
	printf("El escenario es: %s\n\n", Trama.escenario->nombre);

	printf("La complejidad de la trama es: %f\n", complejidad(Trama));

	bool huesped = huespedEsRebelde(William);
	printf("Es William un huesped rebelde? %s\n", huesped? "SI":"NO");

	bool anfitrion = anfitrionEsRebelde(Dolores);
	printf("Es Dolores una anfitriona rebelde? %s\n", anfitrion? "SI":"NO");

	bool huespedes = todosHuespedesRebeldes(Huespedes);
	printf("Son todos los huespedes rebeldes? %s\n", huespedes? "SI":"NO");

	bool trama = esPicante(Trama);
	printf("Es picante la trama? %s\n", trama? "SI":"NO");

	system("pause");
	return 0;
}
