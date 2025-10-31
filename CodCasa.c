#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int lemonadeChange(int* bills, int billsSize);

int main(){
    int* bills;
    int billsSize = 1;

    /*
    printf("Digite uma nota(5, 10 ou 20): ");
    scanf("%d", &answer);

    while (answer != 5 && answer != 10 && answer != 20){
        printf("%d nao eh um valor valido!\nDigite uma nota(5, 10 ou 20): ", answer);
        scanf("%d", &answer);
    };
    bills = (int*)malloc(sizeof(int));
    bills[0] = answer;
    
    while (answer != 0){
        printf("Digite uma nota(5, 10 ou 20) ou 0 (zero) para terminar a fila de notas: ");
        scanf("%d", &answer);

        while (answer != 0 && answer != 5 && answer != 10 && answer != 20){
            printf("%d nao eh um valor valido!\nDigite uma nota(5, 10 ou 20) ou 0 (zero) para terminar a fila de notas: ", answer);
            scanf("%d", &answer);
        };


    }
    */

    srand( time( NULL ) );

    if( ( bills = ( int* )malloc( sizeof( int ) ) ) == NULL ){
        printf("Nao foi possivel criar o vetor!");
        exit(1);
    };

    switch ( rand() % 12 ){
    case 8:
    case 9:
    case 10:
    case 11:
    case 6:
    case 0:
    case 1:
    case 2:
        bills[0] = 5;
        break;
    
    case 7:
    case 3:
    case 4:
        bills[0] = 10;
        break;
    
    case 5:
        bills[0] = 20;
        break;
    };

    while ( rand() % 15 != 0 ){
        if( ( bills = ( int* )realloc( bills, ++billsSize * sizeof( int ) ) ) == NULL ){
            printf("Nao foi possivel expandir o vetor!");
            exit(2);
        };

        switch ( rand() % 12 ){
            case 8:
            case 9:
            case 10:
            case 11:
            case 6:
            case 0:
            case 1:
            case 2:
                bills[billsSize - 1] = 5;
                break;
            
            case 7:
            case 3:
            case 4:
                bills[billsSize - 1] = 10;
                break;
    
            case 5:
                bills[billsSize - 1] = 20;
                break;
        };
    };

    for(int l = 0; l < billsSize; l++){
        printf("%d, ", bills[l]);
    };
    printf("\nResutado: %d", lemonadeChange(bills, billsSize));
    free(bills);
}

unsigned int lemonadeChange(int* bills, int billsSize) {
    unsigned int amount5s = 0, amount10s = 0;

    for( int i = 0; i < billsSize; i++ ){
        switch ( bills[i] ) {
            case 20:
                if( amount10s == 0 ){
                    if( amount5s < 3 ){
                        return 0;
                    };
                    amount5s -= 3;
                }else{
                    if( amount5s == 0 ){
                        return 0;
                    };
                    amount10s--;
                    amount5s--;
                };
                break;
            case 10:
                if( amount5s == 0 ){
                    return 0;
                };
                amount10s++;
                amount5s--;
                break;
            case 5:
                amount5s++;
        };
    };

    return 1;
};