#include <stdio.h>
#include <stdlib.h>

struct nodoLista{
    char dato;
    struct nodoLista *ptrSiguiente;
    struct nodoLista *ptrDoble;
};

typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;

void insertar (ptrNodoLista *ptrS, ptrNodoLista *ptrC, char valor);
char eliminar (ptrNodoLista *ptrS, char valor);

int estaVacia (ptrNodoLista ptrS);
void imprimirLista(ptrNodoLista ptrActual);
void imprimirRegreso(ptrNodoLista ptrActual);
void instrucciones (void);

int main(){
    ptrNodoLista ptrInicial = NULL;
    ptrNodoLista ptrFinal = NULL;
    int eleccion;
    char elemento;

    instrucciones();

    printf("? ");
    scanf("%d", &eleccion);

    while (eleccion != 5){
        switch (eleccion){
        case 1:
            printf("introduce el caracter: ");
            scanf("\n%c", &elemento);
            insertar(&ptrInicial, &ptrFinal, elemento);

            //imprimirLista(ptrInicial);
            break;
        case 2:
            if (!estaVacia(ptrInicial)){
                printf("introduzca un caracter para eliminar: ");
                scanf("\n%c", &elemento);

                if (eliminar(&ptrInicial, elemento)){
                    printf("carater eliminado\n");
                    imprimirLista(ptrInicial);
                }else{
                    printf("no se encontro el caracter\n");
                }
            }else{
                printf("La lista esta vacia\n ");
            }
            break;
        case 3:

            imprimirLista(ptrInicial);
            break;

        case 4:
            imprimirRegreso(ptrFinal);
            break;

        default:
            printf("opcion invañida\n\n");
            instrucciones();
            break;
        }

        printf("? ");
    scanf("%d", &eleccion);
    }

    printf("fin de ejecucion\n");
    return 0;
}

void instrucciones(void){
    printf("seleccione:\n 1) insertar \n 2) eliminar \n 3) imprimir Lista \n 4) imprimir Lista inversa\n 5) Salir\n");
}

void insertar(ptrNodoLista *ptrS, ptrNodoLista *ptrC, char valor){
    ptrNodoLista ptrNuevo;
    ptrNodoLista ptrAnterior;
    ptrNodoLista ptrActual;

    ptrNuevo = malloc(sizeof(NodoLista));

    if (ptrNuevo != NULL){
        ptrNuevo->dato = valor;
        ptrNuevo->ptrSiguiente = NULL;
        ptrNuevo->ptrDoble = NULL;

        ptrAnterior = NULL;
        ptrActual = *ptrS;

        if (*ptrC == NULL){
            printf("El talon esta vacio\n");
            *ptrC = ptrNuevo;
        }


        /*while (ptrActual != NULL && valor > ptrActual->dato){
            ptrAnterior = ptrActual;
            ptrActual = ptrActual->ptrSiguiente;
        }*/

        if (ptrAnterior == NULL){
            ptrNuevo->ptrSiguiente = *ptrS;
            *ptrS = ptrNuevo;
            if (*ptrC != *ptrS){
                ptrActual->ptrDoble = ptrNuevo;
            }
        }else{
            ptrAnterior->ptrSiguiente = ptrNuevo;
            ptrNuevo->ptrSiguiente = ptrActual;
        }

    }else{
        printf("no se inserto, memoria insuficiente\n");
    }
}

char eliminar(ptrNodoLista *ptrS, char valor){
    ptrNodoLista ptrAnterior;
    ptrNodoLista ptrActual;
    ptrNodoLista tempPtr;

    if (valor==(*ptrS)->dato){
        tempPtr = *ptrS;
        *ptrS = (*ptrS)->ptrSiguiente;
        free(tempPtr);
        return valor;
    }else{
        ptrAnterior = *ptrS;
        ptrActual = (*ptrS)->ptrSiguiente;

        while(ptrActual!=NULL && ptrActual->dato!=valor){
            ptrAnterior = ptrActual;
            ptrActual = ptrActual->ptrSiguiente;
        }
        if (ptrActual != NULL){
            tempPtr = ptrActual;
            ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente;
            free(tempPtr);
            return valor;
        }
    }
    return '\0';
}

int estaVacia(ptrNodoLista ptrS){
    return ptrS == NULL;
}

void imprimirLista(ptrNodoLista ptrActual){
    system("clear");
    if (ptrActual == NULL){
        printf("La lista esta vacia \n");
    }else{
        //printf("la lista es esta:\n");
        system("clear");
        while(ptrActual != NULL){
            printf("%c \n", ptrActual->dato);
            ptrActual = ptrActual->ptrSiguiente;
            sleep(1);
            system("clear");
        }
        //printf("NULL\n");
        instrucciones();
    }
}

void imprimirRegreso(ptrNodoLista ptrActual){
    system("clear");
    if (ptrActual == NULL){
        printf("La lista esta vacia \n");
    }else{
        //printf("la lista es esta:\n");
        system("clear");
        while(ptrActual != NULL){
            printf("%c \n", ptrActual->dato);
            ptrActual = ptrActual->ptrDoble;
            sleep(1);
            system("clear");
        }
        //printf("NULL\n");
        instrucciones();
    }
}
