#include <stdio.h>
#include <stdlib.h>

/*Enrique Emmanuel Rios Chyrnia
Youtube: Enrique Rios
*/


typedef char BOOLEAN;
#define TRUE 1;
#define FALSE 2;
#define MAX 8;

typedef struct _AList {
	void** dato;
	int cap;
	int tamActual;
} AList;

AList* crearLista(int longitud);
int agregar(AList* lista, int* valor);
int agregarPos(AList* lista, int* valor, int pos);
int remover(AList* lista, int index);
int redimensionar(AList* list);
BOOLEAN contieneDato(AList* lista, int* dato);
void printAList(AList* lista);

AList* crearLista(int longitud) {
	AList* lista = (AList*)malloc(sizeof(struct _AList));
	if (NULL == lista) return NULL;
	lista->dato = (void**)malloc(sizeof(void*) * longitud);
	if (NULL == lista->dato) {
		free(lista);
		return NULL;
	}
	lista->cap = longitud;
	lista->tamActual = 0;
	return lista;
}


void printAList(AList* lista) {//Imprime la lista.
	int i = 0;
	int* puntero;
	if (NULL == lista)
	{
		exit(0);
	}

	for (i = 0; i < lista->tamActual; i++) {
		puntero = (int*)lista->dato[i];
		printf("dato[%d] = %d \n", i, puntero);
		//printf("dato[%d] = %d \n", i, *puntero);
	}
	printf("end of print\n");
}

//1-Si es nula la lista, retorna 0
//2-Si esta llena, duplica tamaño y agrega valor.
//3-Todo bien, agrega lista, aumenta tamActual.
int agregar(AList* lista, int* valor) {
	if (NULL == lista)return 0;
	
	if (lista->tamActual == lista->cap) {//Lista llena, redimenzinar a (tamaño * 2)
		redimensionar(lista);
		//Luego cargamos el valor.
		lista->dato[lista->tamActual] = *valor;
		lista->tamActual += 1;
		return 0;
	}

	//Encontramos una posicion vacia entonces le metemos el valor
	lista->dato[lista->tamActual] = *valor;
	lista->tamActual += 1;
	
	return TRUE;
}


//Agrega en posicion dada.
//En caso de no existir la posicion, va a ir redimencionando la lista
//Hasta poder poner un numero en dicha posicion
int agregarPos(AList* lista, int* valor, int pos) {
	/*
	while (lista->cap <= pos) {// Si el tamaño de la lista es menor o igual a la posicion, duplicamos el tamaño.
		redimensionar(lista);//de la lista.
	}
	*/
	
	if (lista == NULL)return FALSE; 
	if (pos < 0 || pos >= lista->cap)return FALSE; //Fuera del rango

	lista->dato[pos] = *valor;
	lista->tamActual = pos + 1;
	return TRUE;

}
//Remueve y si no existe ese indice devuelve FALLS
int remover(AList* lista, int index) {
	
	if (lista->cap <= index || index < 0) {
		return FALSE;
	}
	
	lista->dato[index] = NULL;
	return TRUE;
	
}
/*
	Duplica el tamaño de una lista.
	Crea un array TEMP, en el guarda los valores de la lista.
	crea una nueva lista con el doble de tamaño.
	deposita en esta lista los valores guardados en temp.
	libera espacio temp.
*/
int redimensionar(AList* list) {

	int* temp = (int)(malloc(sizeof(int) * (2 * list->cap)));

	for(int i=0; i<list->cap;i++){
	temp[i] = list->dato[i];
	}
	free(list->dato);
	list->dato = temp;
	list->cap = list->cap * 2;
	return TRUE;
	

}

//Pregunta si hay X dato en la lista.
BOOLEAN contieneDato(AList* lista, int* dato) {
	if (lista == NULL) return FALSE;
	for (int i = 0; i < lista->tamActual; i++) {
		if (lista->dato[i] == *dato)return TRUE;
	}
	return FALSE;
}

//Basicamente
/*	crea lista de tamaño 3.
*	agrega 55,56 y 57 en posiciones 0.1.2
*	Borra el elemento en posicion 1-
*	Pregunta si el numero 57 esta en la lista.
*/

/*t main() {
	AList *mi_lista = crearLista(3);
	int valor_1 = 55, valor_2=56, valor_3 = 57;
	agregar(mi_lista, &valor_1);
	agregar(mi_lista, &valor_2);
	agregarPos(mi_lista,&valor_3, 2);
	printAList(mi_lista);

	printf("\n ronda 2---\n");
	remover(mi_lista, 1);
	printAList(mi_lista);

	printf("Contiene el numero 55->  %d \n", contieneDato(mi_lista, &valor_3));
	system("PAUSE");


	return 0;
}

*/
