#include <stdio.h>

int main(){

    /*int parciales[5][3]={{7, 8, 9},
                         {10,7, 8},
                         {9, 10,7},
                         {8, 9, 10},
                         {6, 7, 8}};*/
    int parciales[5][3]={{7, 8, 9},{10,7, 8},{9, 10,7},{8, 9, 10},{6, 7, 8}};

    float promedios[5];

    int i,j;

    float acu, general;
    printf("promedios:\n");

    for (i=0; i<5; i++){
        acu = 0;
        for (j=0; j<3; j++){
            acu += parciales[i][j];
        }
        promedios[i]=acu/3;
        printf("%d) \t %f \n",i+1,promedios[i]);
    }

    acu=0;
    for (i=0; i<5; i++){
        acu+=promedios[i];
    }

    printf("el prom. final es: %f", acu/5);

    return 0;
}
