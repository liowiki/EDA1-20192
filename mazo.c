#include <stdio.h>

void baraja (int wMazo[4][13]);
void reparte (int wMazo[4][13], char *wCara[], char *wPalo[], char *cartaPalo);

int main(){
    char *palo[4] = {"corazones", "Diamantes", "Treboles", "Espadas"};
    char *caras[13] = {"As","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Joto","Reina","Rey"};
    int mazo [4][13] = { 0 };
    int i, j;
    char cartas[52][30];

    srand(time(0));

    baraja(mazo);

    for (i=0; i<4; i++){
        for (j=0; j<13;j++){
            printf("%d \n", mazo[i][j]);
        }
    }

    printf("%p\n", cartas);
    reparte(mazo, caras, palo, cartas);

}


void baraja(int wMazo[4][13]){
    int fila;
    int columna;
    int carta;
    for (carta=1; carta <=52; carta++){
        do{
            fila = rand() % 4;
            columna = rand() % 13;
        }while (wMazo[fila][columna] != 0 );
        wMazo[fila][columna] = carta;
    }
}

void reparte (int wMazo[4][13], char *wCara[], char *wPalo[], char *cartaPalo){
    int fila;
    int columna;
    int carta;
    int i, j;
    char palabra[] = " de ";

    for (carta = 0; carta <=52; carta ++, cartaPalo +=30){
        for (fila=0; fila<=3; fila++){
            for (columna = 0; columna<=12; columna ++){

                if (wMazo[fila][columna] == carta ){
                    j=0;
                    //ciclo que inserta la cara a la carta
                    for (i=0; wCara[columna][i]!='\0'; i++){
                        *(cartaPalo + j) = wCara[columna][i];
                        j++;
                    }
                    //ciclo que inserta " de " a ñla carta
                    for (i=0; i<4; i++){
                        *(cartaPalo + j) = palabra[i];
                        j++;
                    }
                    //ciclo que inserta el palo a la carta
                    for (i=0; wPalo[fila][i]!='\0'; i++){
                        *(cartaPalo + j) = wPalo[fila][i];
                        j++;
                    }

                     *(cartaPalo + j) = '\0';//inserta un final de linea

                }
            }
        }
    }
}
