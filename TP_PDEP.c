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
	anfitrion* Pepe = inicializarAnfitrion("Pepe",70,0.9,RecuerdosDeDolores);

	conocerEscenarioAnfitrion(Dolores,cantina);
	nodo_anfitrion* Anfitriones = NULL;
	Anfitriones = agregarAnfitrionALista(Dolores,Anfitriones);
	Anfitriones = agregarAnfitrionALista(Pepe,Anfitriones);
	mostrarAnfitriones(Anfitriones);

	printf("El nivel de felicidad de Dolores es: %.2f\n",felicidadDeAnfitrion(Dolores));
	printf("El nivel de rebeldia de Dolores es: %.4f\n",rebeldiaDeAnfitrion(Dolores));

	printf("El nivel de fama del escenario Cantina es: %d\n",nivelDeFama(cantina));
	printf("La emotividad del recuerdo de Dolores es: %d\n",emotividad(RecuerdoAmor));

	mostrarEscenario(cantina);
	evolucionarEscenario(cantina);
	mostrarEscenario(cantina);

	huesped* William = inicializarHuesped("William",10,30,Anfitriones,NULL);
	huesped* Pedro = inicializarHuesped("Pedro",20,40,Anfitriones,NULL);
	huesped* Juan = inicializarHuesped("Juan",50,5,Anfitriones,NULL);

	Juan = agregarHuespedALista(Juan,William);
	Pedro = agregarHuespedALista(Pedro,Juan);

	mostrarHuesped(Pedro);
	mostrarHuesped(Pedro);

	float mapeo = mapearFelicidadAnfitriones(Pedro->anfitriones);
	printf("La suma de las felicidades de los anfitriones es: %.2f\n",mapeo);
	mostrarHuesped(Pedro);

	int felicidad = felicidadDeHuesped(William);
	printf("La felicidad de William es: %d\n", felicidad);

	double rebeldia = rebeldiaHuesped(William);
	printf("La rebeldia de William es: %.10lf\n", rebeldia);

	mostrarHuesped(William);
	mostrarEscenario(cantina);
	conocerEscenarioHuesped(William,cantina);
	mostrarHuesped(William);
	mostrarEscenario(cantina);

	anfitrion masFeliz = anfitrionMasFeliz(Anfitriones);
	printf("El anfitrion mas feliz es: %s\n", masFeliz.nombre);

	huesped* masFelizHuesped = huespedMasFeliz(Pedro);
	printf("El huesped mas feliz es: %s\n", masFelizHuesped->nombre);

	return 0;
}
