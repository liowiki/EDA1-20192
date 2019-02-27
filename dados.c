#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void tiraDados(int *apDadosFunc);
void mostrarLanzamiento(int *apDadosFunc2);

int main(){
    int dados[3][5];
    int *apDados;
    int i,j;
    srand(time(0));
    tiraDados(&dados);
    /*for (i=0; i<3; i++){
        for (j=0; j<5; j++){
            printf("%d:%d %d\n",i+1,j+1,dados[i][j]);
        }
    }*/
    mostrarLanzamiento(&dados);
    return 0;
}

void tiraDados(int *apDadosFunc){
    int i;
    for (i=0; i<15;i++){
        *(apDadosFunc + i) = rand() % 6 + 1;
    }
}

void mostrarLanzamiento(int *apDadosFunc2){
    int numDado, numLanzamoento;
    printf("Que dado necesitas conocer 1-3?\n");
    scanf("%d", &numDado);
    printf("en que lanzada 1-5? \n");
    scanf("%d", &numLanzamoento);
    printf("El dado %d en el lanzamiento %d dio: %d", numDado, numLanzamoento, *(apDadosFunc2 + (numDado*3)+numLanzamoento));

}
