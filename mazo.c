#include <stdio.h>

void baraja (int wMazo[4][13]);
void reparte (int wMazo[4][13], char *wCara[], char *wPalo[]);

int main(){
    char *palo[4] = {"corazones", "Diamantes", "Treboles", "Espadas"};
    char *caras[13] = {"As","Dos","Tres","Cuatro","Cinco","Seis","Siete","Ocho","Nueve","Diez","Joto","Reina","Rey"};
    int mazo [4][13] = { 0 };
    int i, j;

    srand(time(0));

    baraja(mazo);

    for (i=0; i<4; i++){
        for (j=0; j<13;j++){
            printf("%d \n", mazo[i][j]);
        }
    }

    reparte(mazo, caras, palo);

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

void reparte (int wMazo[4][13], char *wCara[], char *wPalo[]){
    int fila;
    int columna;
    int carta;
    for (carta = 0; carta <=52; carta ++){
        for (fila=0; fila<=3; fila++){
            for (columna = 0; columna<=12; columna ++){
                if (wMazo[fila][columna] == carta ){
                    printf("%s de %s \n", wCara[columna], wPalo[fila]);
                }
            }
        }
    }
}
