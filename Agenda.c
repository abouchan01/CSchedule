#include <stdio.h>
#include <conio.h>


//Configuramos nuesto nuevo tipo abstracto
//esta estructura va a funcionar para introducir los datos de las tareas
typedef struct nodo{
	int dato;
	char actividad[250];
	char lugar[250];
	int dia;
	char mes[12];
	char hora[8];
	struct nodo* siguiente;
	struct nodo* atras;
}nodo;

//Inicializamos los punteros en un lugar vacío para irlos llenando poco a poco
nodo* primero = NULL;
nodo* ultimo = NULL;

//Declaramos las funciones que vamos a usar el la función principal.
void buscarNodo();
void menu();
void insertarNodo();
void buscarNodo();
void modificarNodo();
void eliminarNodo();
void desplegarListaPU();

int main(){
	system("color 4B");      //Cambia el color de la consola
	int opcionMenu = 0;
	do{
		menu();
		scanf("%d", &opcionMenu);
		switch(opcionMenu){
			case 1:
				printf("\n\n INSERTA TAREA EN LA LISTA \n\n");
				insertarNodo();
				getchar();
				break;
			case 2:
				printf("\n\n BUSCAR UNA TAREA EN LA LISTA \n\n");
				buscarNodo();
				getchar();
				break;	
			case 3:
				printf("\n\n MODIFICAR UNA TAREA \n\n");
				modificarNodo();
				getchar();
				break;
			case 4:
				printf("\n\n ELIMINAR UNA TAREA DE LA LISTA \n\n");
				eliminarNodo();
				getchar();
				break;
			case 5:
				printf("\n\n DESPLEGAR LISTA DE TODAS LAS TAREAS DE LA PRIMERA A LA UTLIMA\n\n");
				desplegarListaPU();
				break;
			case 6:
				printf("\n\n Programa finalizado...");
				return 0;
				break;
			case 7:
				buscarNodo();
				break;
						
			default:
				printf("\n\n Opcion No Valida \n\n");
				getchar();
		}
	}while(opcionMenu != 6);
	return 0;
}

//En la siguiente función configuramos la introduccion
//de un nuevo nodo
void insertarNodo(){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	printf(" Ingrese el dato que contendra el nuevo Nodo: ");
	printf("\n (el dato nos ayuda como ID de la tarea)\n");
	scanf("%i", &nuevo->dato);
	printf(" Ingrese actividad por hacer: ");
	scanf("%s", &nuevo->actividad);
	printf("\nIngrese lugar:");
	scanf( "%s", &nuevo->lugar);
	printf(" Ingrese dia: ");
	scanf("%i", &nuevo->dia); 
	printf(" Ingrese mes:  ");
	scanf("%s", &nuevo->mes);
	printf("ingrese hora: ");
	scanf("%s",&nuevo->hora);
	
	
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		primero->atras = NULL;
		ultimo = primero;
	}else{
		ultimo->siguiente = nuevo;
		nuevo->siguiente = NULL;
		nuevo->atras = ultimo;
		ultimo = nuevo;
	}

	printf("\n Nodo ingresado con exito\n\n");
	getchar();
	getchar();
	system("cls");
}


//En la siguiente funcion buscamos un nodo ya existente
void buscarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar: ");
	scanf("%d", &nodoBuscado);
	
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %d ) Encontrado\n\n", nodoBuscado);
				encontrado = 1;
			}
			
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}


//La siguiente funcion nos permite modificar un nodo o tarea que hicimos previemente
void modificarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	char nodoBuscado = 0;
	int encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar para Modificar: ");
	scanf("%i", &nodoBuscado);
	
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				printf("\n El nodo con el dato ( %i ) Encontrado", nodoBuscado);
				printf("\n Ingrese el nuevo dato para este nodo: ");
				scanf("%i", &actual->dato);
				printf("\n Ingrese la nueva actividad: ");
				scanf("%s", &actual->actividad);
				printf("\n Ingrese el nuevo lugar ");
				scanf("%s", &actual->lugar);
				printf("\n Ingrese el nuevo mes ");
				scanf("%s", &actual->mes);
				printf("\n Ingrese la nueva hora ");
				scanf("%s", &actual->hora);
				printf("\n Ingrese el nuevo dia: ");
				scanf("%i", &actual->dia);
				printf("\n Nodo modificado con exito\n\n");
				encontrado = 1;
			}
			
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

//La siguiente funcion nos permite eliminar un nodo sin afectar a los demás.
void eliminarNodo(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	nodo* anterior = (nodo*)malloc(sizeof(nodo));
	anterior = NULL;
	int nodoBuscado = 0, encontrado = 2;
	printf(" Ingrese el dato del nodo a Buscar para Eliminar: ");
	scanf("%d", &nodoBuscado);
	
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->dato == nodoBuscado){
				
				if(actual==primero){
					primero = primero->siguiente;
					primero->atras = NULL;
				}else if(actual==ultimo){
					anterior->siguiente = NULL;
					ultimo = anterior;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->atras = anterior;
				}
				printf("\n Nodo eliminado con exito\n\n");
				
				encontrado = 1;
			}
			anterior = actual;
			actual = actual->siguiente;
		}
		if(encontrado == 0){
			printf("\n Nodo no Encontrado\n\n");
		}else{
			free(anterior);
		}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

//La siguiente funcion nos muestra todas las tareas pendientes.
void desplegarListaPU(){
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	printf("\nSi quieres el siguiente elemento presiona s, para el anterior presiona a\n");
	printf("Si quieres salir presiona e\n");
	printf("El elemento mas reciente es:\n");
	if(primero!=NULL){
		while(actual != NULL){
	  char Selector;
			printf("\n El dato es: %i", actual->dato);
			printf("\n Su actividad: %s", actual->actividad);
			printf("\n El lugar: %s", actual->lugar);
			printf("\n El dia:%i", actual->dia);
			printf(" de %s", actual->mes);
			//printf("\nDigite su opcion");
			//scanf("%s",&Selector);
			//if(Selector == 's'){
				actual = actual->siguiente;
				getchar();
				getchar();
				system("cls");
			//};
			//if(Selector == 'a'){
			//	actual = actual-> atras;	
			//	if (actual -> atras == NULL){
			//	actual->atras = ultimo;
			//	};
			};
		//}
	}else{
		printf("\n La lista se encuentra vacia\n\n");
		getchar();
		getchar();
		system("cls");
	}
}


//La siguiente funcion nos muestra el menu principal.
void menu(){
	int opcionMenu = 0;
		printf("\n|-------------------------------------|");
		printf("\n|           Tareas pendientes         |");
		printf("\n|------------------|------------------|");
		printf("\n| 1. Insertar      | 5.Desplegar todo |");
		printf("\n| 2. Buscar        | 6.Salir          |");
		printf("\n| 3. Modificar     | 7. Busqueda      |");
		printf("\n| 4. Eliminar      |                  |");		
		printf("\n|******************|******************|");
		printf("\n\n Escoja una Opcion: ");
}



//Aqui rato de explicar resumidamente el como funciona una lista doblemente ligada.
// 13, 16, 2, 9

// primero = 13      ultimo = 9      nuevo = 9      nodoBuscado = 2   encontrado = 0            actual    =  9        anterior   =  2                      13    16   2  9
 
// lista doble ------ NULL <- 13 -> <- 5 -> <- 2 -> <- 9 -> NULL  actual = null                                    9  2  16  13










