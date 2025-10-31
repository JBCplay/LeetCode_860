bool lemonadeChange(int* bills, int billsSize) {
    int i, j = 0, bills5 = 0, bills10 = 0, bills20 = 0, canReturn20sW10, returnNeeds5, returnNeeds15;


    for( i = 0, j = 0; i < billsSize && bills[i] == 5 ; i++, j++ );
    bills5 = j;

    j = 0;
    for( ; i < billsSize && bills[i] == 10 ; i++, j++ );
    bills10 = j;

    j = 0;
    for( ; i < billsSize && bills[i] == 20 ; i++, j++ );
    bills20 = j;
/*


    for(i = 0; i < billsSize; i++){
        if(bills[i] == 5){
            bills5++;
            continue;
        };
        if(bills[i] == 10){
            bills10++;
            continue;
        };
        if(bills[i] == 20){
            bills20++;
        };
    };
*/
    bills5 = bills5 - bills10;
    if(bills5 < 0){
        return false;
    };

    canReturn20sW10 = bills20 - bills10;//notas de 20 que conseguem ser trocadas com notas de 10

    if(canReturn20sW10 < 0){
        canReturn20sW10 = bills20;
    };

    //verificar
    bills20 = bills20 - canReturn20sW10;

    returnNeeds5 = bills5 - canReturn20sW10;
    if(returnNeeds5 < 0){
        return false;
    };
    bills5 = returnNeeds5;

    returnNeeds15 = bills5 - (3 * bills20);

    //consertar
    if(returnNeeds15 < 0){
        return false;
    };

    return true;
}
