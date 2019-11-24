#include "libreria.h"

anfitrion* inicializarAnfitrion(char* nombre,int energia,float procesamiento,nodo_recuerdo* Recuerdos){
	anfitrion* nuevoAnfitrion = malloc(sizeof(anfitrion));
	nuevoAnfitrion->nombre = strdup(nombre);
	nuevoAnfitrion->energia = energia;
	nuevoAnfitrion->procesamiento = procesamiento;
	nuevoAnfitrion->recuerdos = Recuerdos;
	return nuevoAnfitrion;
}

huesped* inicializarHuesped(char* nombre,int energia,int minutosRestantes,nodo_anfitrion* Anfitriones, huesped* Huespedes){
	huesped* nuevoHuesped = malloc(sizeof(huesped));
	nuevoHuesped->nombre = strdup(nombre);
	nuevoHuesped->energia = energia;
	nuevoHuesped->minutosRestantes = minutosRestantes;
	nuevoHuesped->anfitriones = Anfitriones;
	nuevoHuesped->siguiente = Huespedes;
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

huesped* agregarHuespedALista(huesped* Huesped, huesped* otroHuesped){
	huesped* nuevoHuesped = Huesped;
	while(nuevoHuesped->siguiente != NULL){
		nuevoHuesped = nuevoHuesped->siguiente;
	}
	nuevoHuesped->siguiente = otroHuesped;
	return Huesped;
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
		huesped* aux2 = Huesped;
		printf("\nHuespedes amigos: ");
		while(aux2 != NULL){
			printf("%s ",aux2->nombre);
			aux2 = aux2->siguiente;
		}
		printf("\n");
}

void mostrarEscenario(escenario* Escenario){
	printf("El nombre del escenario es: %s\n",Escenario->nombre);
	if(strcmp(((bajoCoste*)Escenario->categoria)->nombre,"bajoCoste")==0){
		printf("La categoria del escenario es: %s\n",((bajoCoste*)Escenario->categoria)->nombre);
	}
	else if(strcmp(((estandar*)Escenario->categoria)->nombre,"bajoCoste")==0){
		printf("La categoria del escenario es: %s\n",((estandar*)Escenario->categoria)->nombre);
	}
	else{
		printf("La categoria del escenario es: %s\n",((deLujo*)Escenario->categoria)->nombre);
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

void conocer(anfitrion* Anfitrion,escenario* Escenario){
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

int felicidadHuesped(huesped* Huesped){
	float felicidadAmigosAnfitriones = mapearFelicidadAnfitriones(Huesped->anfitriones);
	float minutosRestantes = Huesped->minutosRestantes;
	float acumulador = felicidadAmigosAnfitriones;
	if(Huesped->siguiente != NULL){
		acumulador += felicidadHuesped(Huesped->siguiente);
	}

	return acumulador*minutosRestantes;
}
