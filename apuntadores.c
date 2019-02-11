#include <stdio.h>

int main(){
    int a;
    int *ptrA;

    a=7;
    ptrA = &a;

    printf("la direccion de a es %p \n"
           "el valor de ptrA es %p \n", &a, ptrA);

    printf("El valor de a es %d \n"
           "El valor de *ptrA es %d", a, *ptrA);

    return 0;
}
