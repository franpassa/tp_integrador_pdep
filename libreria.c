#include "libreria.h"

anfitrion* inicializarAnfitrion(char* nombre,int energia,float procesamiento,nodo_recuerdo* Recuerdos){
	anfitrion* nuevoAnfitrion = malloc(sizeof(anfitrion));
	nuevoAnfitrion->nombre = strdup(nombre);
	nuevoAnfitrion->energia = energia;
	nuevoAnfitrion->procesamiento = procesamiento;
	nuevoAnfitrion->recuerdos = Recuerdos;
	return nuevoAnfitrion;
}

huesped* inicializarHuesped(char* nombre,int energia,int minutosRestantes,nodo_anfitrion* Anfitriones, nodo_huesped* Huespedes){
	huesped* nuevoHuesped = malloc(sizeof(huesped));
	nuevoHuesped->nombre = strdup(nombre);
	nuevoHuesped->energia = energia;
	nuevoHuesped->minutosRestantes = minutosRestantes;
	nuevoHuesped->anfitriones = Anfitriones;
	nuevoHuesped->huespedes = Huespedes;
	return nuevoHuesped;
}

recuerdo* inicializarRecuerdo(char* descripcion, escenario* Escenario){
    recuerdo* nuevoRecuerdo = malloc(sizeof(recuerdo));
    nuevoRecuerdo->descripcion = strdup(descripcion);
    nuevoRecuerdo->Escenario = Escenario;
    return nuevoRecuerdo;
}

escenario* inicializarEscenario(char* nombre,void* categoria){
    escenario* nuevoEscenario = malloc(sizeof(escenario));
    nuevoEscenario->nombre = nombre;
    nuevoEscenario->categoria = categoria;
    return nuevoEscenario;
}

bajoCoste* inicializarTipoBajoCoste(char* zona){
	bajoCoste* nuevoTipo = malloc(sizeof(bajoCoste));
	nuevoTipo->nombre = "bajoCoste";
	nuevoTipo->zona = zona;
	return nuevoTipo;
}

estandar* inicializarTipoEstandar(){
	estandar* nuevoTipo = malloc(sizeof(estandar));
	nuevoTipo->nombre = "estandar";
	return nuevoTipo;
}

deLujo* inicializarTipoDeLujo(int visitas){
	deLujo* nuevoTipo = malloc(sizeof(deLujo));
	nuevoTipo->nombre = "deLujo";
	nuevoTipo->visitas = visitas;
	return nuevoTipo;
}

nodo_recuerdo* agregarRecuerdoALista(recuerdo* Recuerdo,nodo_recuerdo* Lista){
    nodo_recuerdo* nuevoNodo = (nodo_recuerdo*)malloc(sizeof(nodo_recuerdo));
    nuevoNodo->Recuerdo = *Recuerdo;
    nuevoNodo->siguiente = Lista;
    return nuevoNodo;
}

nodo_anfitrion* agregarAnfitrionALista(anfitrion* Anfitrion, nodo_anfitrion* Lista){
    nodo_anfitrion* nuevoNodo = (nodo_anfitrion*)malloc(sizeof(nodo_anfitrion));
    nuevoNodo->anfitrion = *Anfitrion;
    nuevoNodo->siguiente = Lista;
    return nuevoNodo;
}

nodo_huesped* agregarHuespedALista(huesped* Huesped, nodo_huesped* Lista){
    nodo_huesped* nuevoNodo = (nodo_huesped*)malloc(sizeof(nodo_huesped));
    nuevoNodo->huesped = *Huesped;
    nuevoNodo->siguiente = Lista;
    return nuevoNodo;
}

void mostrarRecuerdos(nodo_recuerdo* Lista){
    while(Lista!=NULL){
        printf("Recuerdo: %s\n",Lista->Recuerdo.descripcion);
        Lista = Lista->siguiente;
    }
}

void mostrarAnfitriones(nodo_anfitrion* Lista){
	while(Lista!=NULL){
		printf("Nombre: %s\n",Lista->anfitrion.nombre);
		printf("Energia: %d\n",Lista->anfitrion.energia);
		printf("Procesamiento: %.2f\n",Lista->anfitrion.procesamiento);
		mostrarRecuerdos(Lista->anfitrion.recuerdos);
		Lista = Lista->siguiente;
	}
}

void mostrarHuesped(huesped* Huesped){
		printf("Nombre: %s\n", Huesped->nombre);
		printf("Energia: %d\n", Huesped->energia);
		printf("Minutos restantes: %d\n", Huesped->minutosRestantes);
		printf("Anfitriones amigos: ");
		nodo_anfitrion* aux = Huesped->anfitriones;
		while(aux != NULL){
			printf("%s ",aux->anfitrion.nombre);
			aux = aux->siguiente;
		}
		free(aux);
		nodo_huesped* aux2 = Huesped->huespedes;
		printf("\nHuespedes amigos: ");
		while(aux2 != NULL){
			printf("%s ",aux2->huesped.nombre);
			aux2 = aux2->siguiente;
		}
		printf("\n");
}

void mostrarEscenario(escenario* Escenario){
	printf("El nombre del escenario es: %s\n",Escenario->nombre);
	if(strcmp(((bajoCoste*)Escenario->categoria)->nombre,"bajoCoste")==0){
		printf("La categoria del escenario es: %s\n",((bajoCoste*)Escenario->categoria)->nombre);
		printf("La zona del escenario es: %s\n",((bajoCoste*)Escenario->categoria)->zona);
	}
	else if(strcmp(((estandar*)Escenario->categoria)->nombre,"estandar")==0){
		printf("La categoria del escenario es: %s\n",((estandar*)Escenario->categoria)->nombre);
	}
	else{
		printf("La categoria del escenario es: %s\n",((deLujo*)Escenario->categoria)->nombre);
		printf("La cantidad de visitas del escenario es: %d\n",((deLujo*)Escenario->categoria)->visitas);
	}
}

float felicidadDeAnfitrion(anfitrion* Anfitrion){
	return (Anfitrion->energia/Anfitrion->procesamiento);
}

float rebeldiaDeAnfitrion(anfitrion* Anfitrion){
	return 1/felicidadDeAnfitrion(Anfitrion);
}

int nivelDeFama(escenario* Escenario){
	if (strcmp(((bajoCoste*)Escenario->categoria)->nombre,"bajoCoste")==0){
		return 100+strlen(((bajoCoste*)Escenario->categoria)->zona);
	}
	else if (strcmp(((deLujo*)Escenario->categoria)->nombre,"deLujo")==0){
		return 100+((deLujo*)Escenario->categoria)->visitas;
	}
	else{
		return 110;
	}
}

int emotividad(recuerdo* Recuerdo){
	int largo = strlen(Recuerdo->descripcion);
	int fama = nivelDeFama(Recuerdo->Escenario);
	return largo*fama;
}

escenario* evolucionarEscenario(escenario* Escenario){
	if(strcmp(((bajoCoste*)Escenario->categoria)->nombre,"bajoCoste")==0){
		//Aca se me complica, porque no puedo asignarle a la categoria un tipo hipotetico, tiene que existir.
		estandar* estandar = malloc(sizeof(estandar));
		estandar->nombre = "estandar";
		Escenario->categoria = estandar;
		return Escenario;
	}
	else if(strcmp(((estandar*)Escenario->categoria)->nombre,"estandar")==0){
		deLujo* deLujo = malloc(sizeof(deLujo));
		deLujo->nombre = "deLujo";
		deLujo->visitas = 1;
		Escenario->categoria = deLujo;
		return Escenario;
	}
	else{
		printf("\tError: no se puede evolucionar\n");
		return Escenario;
	}
}

char* strconcat(char *s,char *t)
{
    char *p=malloc(strlen(s)+strlen(t)+1);    /* 3: you will have to reserve memory to hold the copy. */
    int ptr =0, temp = 0;                   /* 4 initialise some helpers */

    while(s[temp]!='\0'){                  /* 5. use the temp to "walk" over string 1 */
        p[ptr++] = s[temp++];
    }
    temp=0;
    while(t[temp]!='\0'){                   /* and string two */
        p[ptr++]=t[temp++];
    }
    return p;
}

void conocerEscenarioAnfitrion(anfitrion* Anfitrion,escenario* Escenario){
	recuerdo* nuevoRecuerdo = malloc(sizeof(recuerdo));
	nuevoRecuerdo->descripcion = strconcat("Conoce el escenario ",Escenario->nombre);
	nuevoRecuerdo->Escenario = Escenario;
	Anfitrion->recuerdos = agregarRecuerdoALista(nuevoRecuerdo,Anfitrion->recuerdos);
}

float mapearFelicidadAnfitriones(nodo_anfitrion* Anfitriones){
	float acumulador = 0;
	anfitrion* actual = malloc(sizeof(anfitrion));
	while (Anfitriones != NULL){
		actual = inicializarAnfitrion(Anfitriones->anfitrion.nombre,Anfitriones->anfitrion.energia,Anfitriones->anfitrion.procesamiento,Anfitriones->anfitrion.recuerdos);
		acumulador += felicidadDeAnfitrion(actual);
		Anfitriones = Anfitriones->siguiente;
	}
	return acumulador;
}

float mapearFelicidadHuespedes(nodo_huesped* Huespedes){
	float acumulador = 0;
	huesped* actual = malloc(sizeof(anfitrion));
	while (Huespedes != NULL){
		actual = inicializarHuesped(Huespedes->huesped.nombre,Huespedes->huesped.energia,Huespedes->huesped.minutosRestantes,Huespedes->huesped.anfitriones,Huespedes->huesped.huespedes);
		acumulador += felicidadDeHuesped(actual);
		Huespedes = Huespedes->siguiente;
	}
	return acumulador;
}

int felicidadDeHuesped(huesped* Huesped){
	float felicidadAmigosAnfitriones = mapearFelicidadAnfitriones(Huesped->anfitriones);
	float felicidadAmigosHuespedes = mapearFelicidadHuespedes(Huesped->huespedes);
	float minutosRestantes = Huesped->minutosRestantes;
	float acumulador = felicidadAmigosAnfitriones + felicidadAmigosHuespedes;
	return acumulador*minutosRestantes;
}

double rebeldiaHuesped(huesped* Huesped){
	double felicidad = felicidadDeHuesped(Huesped);
	return 1/felicidad;
}

void conocerEscenarioHuesped(huesped* Huesped, escenario* Escenario){
	Huesped->minutosRestantes -= 10;
	if(strcmp(((deLujo*)Escenario->categoria)->nombre,"deLujo")==0){
		((deLujo*)Escenario->categoria)->visitas += 1;
	}
}

float ini_felicidadAnfitrion(anfitrion Anfitrion){
	anfitrion* nuevoAnfitrion = malloc(sizeof(anfitrion));
	nuevoAnfitrion = inicializarAnfitrion(Anfitrion.nombre,Anfitrion.energia,Anfitrion.procesamiento,Anfitrion.recuerdos);
	float felicidad = felicidadDeAnfitrion(nuevoAnfitrion);
	return felicidad;
}

float ini_felicidadHuesped(huesped Huesped){
	huesped* nuevoHuesped = malloc(sizeof(huesped));
	nuevoHuesped = inicializarHuesped(Huesped.nombre,Huesped.energia,Huesped.minutosRestantes,Huesped.anfitriones,Huesped.huespedes);
	float felicidad = felicidadDeAnfitrion(nuevoHuesped);
	return felicidad;
}

anfitrion anfitrionMasFeliz(nodo_anfitrion* Anfitriones){
	anfitrion elMasFeliz = Anfitriones->anfitrion;
	while(Anfitriones->siguiente != NULL){
		if(ini_felicidadAnfitrion(elMasFeliz)<ini_felicidadAnfitrion(Anfitriones->siguiente->anfitrion)){
			elMasFeliz = Anfitriones->siguiente->anfitrion;
		}
		Anfitriones = Anfitriones->siguiente;
	}
	return elMasFeliz;
}

huesped huespedMasFeliz(nodo_huesped* Huespedes){
	huesped elMasFeliz = Huespedes->huesped;
	while(Huespedes->siguiente != NULL){
		if(ini_felicidadHuesped(elMasFeliz)<ini_felicidadHuesped(Huespedes->siguiente->huesped)){
			elMasFeliz = Huespedes->siguiente->huesped;
		}
		Huespedes = Huespedes->siguiente;
	}
	return elMasFeliz;
}

float complejidad(trama Trama){
	int nivelFama = nivelDeFama(Trama.escenario);
	float felicidadHuesped = ini_felicidadHuesped(huespedMasFeliz(Trama.huespedes));
	float felicidadAnfitrion = ini_felicidadAnfitrion(anfitrionMasFeliz(Trama.anfitriones));
	if(felicidadHuesped>felicidadAnfitrion){
		return nivelFama/felicidadHuesped;
	}
	else{
		return nivelFama/felicidadAnfitrion;
	}
}

bool huespedEsRebelde(huesped* Huesped){
	return rebeldiaHuesped(Huesped)>10;
}

bool anfitrionEsRebelde(anfitrion* Anfitrion){
	return rebeldiaDeAnfitrion(Anfitrion)>10;
}

bool todosAnfitrionesRebeldes(nodo_anfitrion* Anfitriones){
	bool booleano;
	while(Anfitriones->siguiente != NULL){
		if(anfitrionEsRebelde(inicializarAnfitrion(Anfitriones->anfitrion.nombre,Anfitriones->anfitrion.energia,Anfitriones->anfitrion.procesamiento,Anfitriones->anfitrion.recuerdos))==1){
			booleano = true;
		}
		else{
			booleano = false;
			return booleano;
		}
		Anfitriones = Anfitriones->siguiente;
	}
	return booleano;
}

bool todosHuespedesRebeldes(nodo_huesped* Huespedes){
	bool booleano;
	while(Huespedes->siguiente != NULL){
		if(huespedEsRebelde(inicializarHuesped(Huespedes->huesped.nombre,Huespedes->huesped.energia,Huespedes->huesped.minutosRestantes,Huespedes->huesped.anfitriones,Huespedes->huesped.huespedes))){
			booleano = true;
		}
		else{
			booleano = false;
			return booleano;
		}
		Huespedes = Huespedes->siguiente;
	}
	return booleano;
}

bool esPicante(trama Trama){
	bool booleano;
	if(todosHuespedesRebeldes(Trama.huespedes)&&todosAnfitrionesRebeldes(Trama.anfitriones)){
		booleano = true;
		return booleano;
	}
	else{
		booleano = false;
		return booleano;
	}
}

void matarAnfitrionesRebeldes(nodo_anfitrion* Anfitriones){
	while(Anfitriones != NULL){
		anfitrion* anfitrion_actual = inicializarAnfitrion(Anfitriones->anfitrion.nombre,Anfitriones->anfitrion.energia,Anfitriones->anfitrion.procesamiento,Anfitriones->anfitrion.recuerdos);
		if(anfitrionEsRebelde(anfitrion_actual)){
		Anfitriones->anfitrion.energia = 0;
		}
		Anfitriones = Anfitriones->siguiente;
	}
}

void matarHuespedesRebeldes(nodo_huesped* Huespedes){
	while(Huespedes != NULL){
		huesped* huesped_actual = inicializarHuesped(Huespedes->huesped.nombre,Huespedes->huesped.energia,Huespedes->huesped.minutosRestantes,Huespedes->huesped.anfitriones,Huespedes->huesped.huespedes);
		if(huespedEsRebelde(huesped_actual)){
			Huespedes->huesped.energia = 0;
		}
		Huespedes = Huespedes->siguiente;
	}
}

void renovar(trama Trama){
	evolucionarEscenario(Trama.escenario);
	matarHuespedesRebeldes(Trama.huespedes);
	matarAnfitrionesRebeldes(Trama.anfitriones);
}
