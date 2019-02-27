#include <stdio.h>
#include <stdlib.h>

struct nodoLista{
    char dato;
    struct nodoLista *ptrSiguiente;
};

typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;

void insertar (ptrNodoLista *ptrS, char valor);
char eliminar (ptrNodoLista *ptrS, char valor);

int estaVacia (ptrNodoLista ptrS);
void imprimirLista(ptrNodoLista ptrActual);
void instrucciones (void);

int main(){
    ptrNodoLista ptrInicial = NULL;
    int eleccion;
    char elemento;

    instrucciones();

    printf("? ");
    scanf("%d", &eleccion);

    while (eleccion != 3){
        switch (eleccion){
        case 1:
            printf("introduce el caracter: ");
            scanf("\n%c", &elemento);
            insertar(&ptrInicial, elemento);

            imprimirLista(ptrInicial);
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
    printf("seleccione:\n 1) insertar \n 2)eliminar \n 3)salir\n ");
}

void insertar(ptrNodoLista *ptrS, char valor){
    ptrNodoLista ptrNuevo;
    ptrNodoLista 
    ptrAnterior;
    ptrNodoLista ptrActual;

    ptrNuevo = malloc(sizeof(NodoLista));

    if (ptrNuevo != NULL){
        ptrNuevo->dato = valor;
        ptrNuevo->ptrSiguiente = NULL;

        ptrAnterior = NULL;
        ptrActual = *ptrS;

        
        while (ptrActual != NULL && valor > ptrActual->dato){
            ptrAnterior = ptrActual;
            ptrActual = ptrActual->ptrSiguiente;
        }

        if (ptrAnterior == NULL){
            ptrNuevo->ptrSiguiente = *ptrS;
            *ptrS = ptrNuevo;
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
    if (ptrActual == NULL){
        printf("La lista esta vacia \n");
    }else{
        printf("la lista es esta:\n");
        while(ptrActual != NULL){
            printf("%c --> ", ptrActual->dato);
            ptrActual = ptrActual->ptrSiguiente;
        }
        printf("NULL\n");
    }
}
