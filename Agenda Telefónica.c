#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



typedef char BOOLEAN;
#define TRUE 1;
#define FALSE 2;
#define MAX 8;



typedef struct {
	char nombre[30];
	char numero[15];
}Usuario;

typedef struct {
	Usuario* datos;
	int cap;
	int tamActual;
} Agenda;

 Agenda* crearAgenda(int longitud) {
	 Agenda* agenda = (Agenda*)malloc(sizeof(Agenda));
	if (NULL == agenda) return NULL;
	agenda->datos = (Usuario*)malloc(sizeof(Usuario) * longitud);
	if (NULL == agenda->datos) {
		free(agenda);
		return NULL;
	}
	agenda->cap = longitud;
	agenda->tamActual = 0;
	return agenda;
}

int agregar(Agenda* agenda, Usuario valor) {
	if (NULL == agenda)return 0;

	//Encontramos una posicion vacia entonces le metemos el valor
	agenda->datos[agenda->tamActual] = valor;
	agenda->tamActual += 1;

	return TRUE;
}
//Busca y retorna un numero. Null si no esta.
int* buscar(Agenda* agenda, char* nombre) {
	if (agenda == NULL) return NULL;
	if (nombre == NULL) return NULL;

	for (int i = 0;i < agenda->tamActual; i++) {
		if (*agenda->datos[i].nombre == *nombre) {
			return &agenda->datos[i];
		}
	}

	return FALSE;
}

void start() {
	int respuesta = 0;
	char basura;
	char texto[30];
	Usuario persona;
	Usuario* pPersona;
	Agenda* agenda = crearAgenda(3);


	while (respuesta != 3) {
		printf("\n****************************************");
		printf("\n********* AGENDA TELEFÓNICA ************");
		printf("\n****************************************");
		printf("\n1. Agregar contacto ");
		printf("\n2. Buscar contacto ");
		printf("\n2. Buscar contacto ");
		printf("\n3. Salir \n");

		scanf_s("%i", &respuesta);
		scanf_s("%c", &basura); //elimina el Enter.

		switch (respuesta) {
		case 1:
			printf("\n********* INTRODUZCA NOMBRE ************");
			printf("\n----> ");
			gets(texto);
			strcpy(persona.nombre, texto, texto);
			printf("\n******* INTRODUZCA EL TELEFONO ********\n");
			gets(texto);
			strcpy(persona.numero, texto, texto);
			agregar(agenda, persona);
			break;
		case 2:
			printf("\n*************  BUSQUEDA  *************");
			printf("\n********* INTRODUZCA NOMBRE ************");
			printf("\n----> ");
			gets(texto);
			pPersona = buscar(agenda, texto);
			if (pPersona == 2) {
				printf("\n********* No encontrado ************\n");
				break;
			}
			printf("\n*************  Resultado  *************\n");
			printf("Nombre: %s Telefono: %s", pPersona->nombre, pPersona->numero);

			break;
		case 3:
			exit(0);
			break;
		default:
			printf("\n Introdujo un valor incorrecto \n");
		}
	}



}


int main() {
	start();
}
