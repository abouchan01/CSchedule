#include <stdio.h>
#include <conio.h>


//Configuramos nuesto nuevo tipo abstracto
//esta estructura va a funcionar para introducir los datos de las tareas
typedef struct nodo{
	int dato;
	char actividad[250];
	char lugar[250];
	int dia;
	int mes;
	char hora[8];
	char status[20];
	struct nodo* siguiente;
	struct nodo* atras;
}nodo;

//La siguiente variable contendrá el numero de tareas que tenemos enlistadas.
int numeroDeNodos = 0;

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
void bubbleSort();
void ActividadesMes();

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
				system("cls");
				break;
			case 2:
				printf("\n\n BUSCAR UNA TAREA EN LA LISTA \n\n");
				buscarNodo();
				getchar();
				getchar();
				system("cls");
				break;	
			case 3:
				printf("\n\n MODIFICAR UNA TAREA \n\n");
				modificarNodo();
				getchar();
				getchar();
				system("cls");
				break;
			case 4:
				printf("\n\n ELIMINAR UNA TAREA DE LA LISTA \n\n");
				eliminarNodo();
				getchar();
				getchar();
				system("cls");
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
			case 8:
				printf("las tareas enlistadas son: %i", numeroDeNodos);
				getchar();
				getchar();
				system("cls");
				break;
			
			case 9:
				bubbleSort();
				break;
			case 10:
				ActividadesMes();
				break;
						
			default:
				printf("\n\n Opcion No Valida \n\n");
				getchar();
				getchar();
		}
	}while(opcionMenu != 6);
	return 0;
}

//En la siguiente función configuramos la introduccion
//de un nuevo nodo
void insertarNodo(){
	nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	printf("\nIngrese el dato que contendra el nuevo Nodo:  (numero) ");
	printf("\n (el dato nos ayuda como ID de la tarea)\n");
	scanf("%i", &nuevo->dato);
	printf("\nSi los siguientes datos requieren de espacios, por favor en lugar de el usa guion bajo o notacion upper-lower cammel");
	printf("\nIngrese actividad por hacer: ");
	scanf("%s", &nuevo->actividad);
	printf("\nIngrese lugar:");
	scanf( "%s", &nuevo->lugar);
	printf("\nIngrese dia:(numero) ");
	scanf("%i", &nuevo->dia); 
	printf("\nIngrese mes:  ");
	scanf("%i", &nuevo->mes);
	printf("\nIngrese hora: ");
	scanf("%s",&nuevo->hora);
	printf("\nIngrese status (completado/ incompleto): ");
	scanf("%s",&nuevo->status);
	
	
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
	numeroDeNodos += 1;
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
				scanf("%i", &actual->mes);
				printf("\n Ingrese la nueva hora ");
				scanf("%s", &actual->hora);
				printf("\n Ingrese el nuevo status ");
				scanf("%s", &actual->status);
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
	//printf("Si quieres salir presiona e\n");
	printf("El elemento mas reciente es:\n");
	if(primero!=NULL){
		while(actual != NULL){
			printf("\n El dato es: %i", actual->dato);
			printf("\n Su actividad: %s", actual->actividad);
			printf("\n El lugar: %s", actual->lugar);
			printf("\n El dia:%i", actual->dia);
			printf(" de %i", actual->mes);
			printf("\n a las: %s", actual->hora);
			printf("\n Status: %s ", actual->status);
			printf("\nPresione enter para ver la siguiente tarea\n");
			getchar();
				actual = actual->siguiente;
				getchar();
				getchar();
			system("cls");
			};
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
		printf("\n| 4. Eliminar      | 8.¿cuantas tareas|");
		printf("\n|                  | tengo pendientes?|");
		printf("\n|                  |                  |");		
		printf("\n|******************|******************|");
		printf("\n\n Escoja una Opcion: ");
}


//Aqui trato de explicar resumidamente el como funciona una lista doblemente ligada.
// 13, 16, 2, 9

// primero = 13      ultimo = 9      nuevo = 9      nodoBuscado = 2   encontrado = 0            actual    =  9        anterior   =  2                      13    16   2  9
 
// lista doble ------ NULL <- 13 -> <- 5 -> <- 2 -> <- 9 -> NULL  actual = null                                    9  2  16  13



void bubbleSort(){
	int i=0,viejo;
	nodo* actual = (nodo*)malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			for(i=0;numeroDeNodos-1;actual = actual->siguiente){        //con base en cuantos nodos tenemos
			printf("avanzar\n");
				//if(actual->mes<actual.siguiente->mes){
				//	actual.dato = viejo;
				//	nuevo.mes = nuevo.siguiente;
				//	nuevo.siguiente = viejo; 
				};
					
			}
			//actual = actual->siguiente;
			getchar();
			getchar();
			system("cls");
		}else{
		printf("\n La lista se encuentra vacia\n\n");
		getchar();
		getchar();
		system("cls");
	}
	
}

void ActividadesMes(){
	char mes[12];
	//nodo* nuevo = (nodo*)malloc(sizeof(nodo));
	nodo* actual = (nodo*)malloc(sizeof(nodo));
		int nodoBuscado = 0, encontrado = 0;
	printf(" Ingrese el dato del nodo a Buscar:" );
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
	
	
	
	
	printf("¿De que mes quieres ver tus actividades?\n");
	scanf("%i",mes);
	while(mes == actual->mes){
			printf("\n El dato es: %i", actual->dato);
			printf("\n Su actividad: %s", actual->actividad);
			printf("\n El lugar: %s", actual->lugar);
			printf("\n El dia:%i", actual->dia);
			printf(" de %i", actual->mes);
			printf("\n a las: %s", actual->hora);
			printf("\n Status: %s ", actual->status);
			printf("\nPresione enter para ver la siguiente tarea\n");
			getchar();
			actual = actual->siguiente;
	}

}
}




