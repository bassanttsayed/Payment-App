#include<stdio.h>
#include"app.h"

extern ST_cardData_t cardinf;
extern ST_terminalData_t terminalinfo;
void appStart(void){
    ST_transaction_t trans;
    ST_cardData_t cd;
    ST_terminalData_t td;
    getCardHolderName(&cd);
    getCardExpiryDate(&cd);
    getCardPAN(&cd);
    getTransactionDate(&td);
    isCardExpired(cardinf,terminalinfo);
    getTransactionAmount(&td);
    setMaxAmount(&td);
    getTransactionAmount(&td);
    isBelowMaxAmount(&td);
    isValidAccount(&cd);
    isAmountAvailable(&td);
    saveTransaction(&trans);
    recieveTransactionData(&trans);


}
