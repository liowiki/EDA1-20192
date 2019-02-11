#include <stdio.h>

int cuboPorValor(int n);
void cuboPorReferencia (int *ptrN);

int main(){
    int numero=5;

    printf("El valor real de numero es %d\n", numero);

    numero = cuboPorValor(numero);

     printf("el cubo del numero es %d\n", numero);

    numero = 5;

    cuboPorReferencia(&numero);

    printf("el cubo del numero es %d\n", numero);

}

int cuboPorValor(int n){

    return n * n * n;

}

void cuboPorReferencia(int *ptrN){

    *ptrN = *ptrN * *ptrN * *ptrN;
}
