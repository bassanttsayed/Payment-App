#include <stdio.h>
#include <stdlib.h>
#include"CardModule/CardModule.h"
#include"TerminalModule/TerminalModule.h"
#include"ServerModule/ServerModule.h"
#include"app/app.h"

extern ST_transaction_t transactionArray[3];
extern ST_cardData_t cardinf;
extern ST_terminalData_t terminalinfo;
extern int countArr;
int main()
{
   // appStart();
  // printf("*****");
//    float res=((transactionArray[0]).terminalData.transAmount);
   //// printf("%f",(transactionArray[0].terminalData.transAmount));
    //printf("Hello world!\n");
   // int x [10];
    //for(int i=0; i<10; i++){
      //  scanf("%s",&x);
    //    printf("%s",x);
    //}

    ST_cardData_t ptr;
    //getCardHolderName(&ptr);
  //  getCardExpiryDate(&ptr);
    getCardPAN(&ptr);
 /////////*****   getCardPAN(&ptr);

  /////////*****   ST_terminalData_t p;
   /////////*****  setMaxAmount(&p);
   /////////*****  ST_transaction_t trans;
   /////////*****  getTransactionAmount(&p);
ST_terminalData_t p;
setMaxAmount(&p);
getTransactionAmount(&p);
isBelowMaxAmount(&p);
isValidAccount(&ptr);
isAmountAvailable(&p);
//setMaxAmount(&p);


   /////////*****  isBelowMaxAmount(&p);
  //  getTransactionDate(&p);
    //isCardExpired(cardinf,terminalinfo);
    //setMaxAmount(&p);
    //ST_transaction_t ppp;
    /////////***** isValidAccount(&ptr);
    /////////***** isAmountAvailable(&p);
    /////////***** saveTransaction(&trans);
    /////////***** recieveTransactionData(&trans);
    /////////***** printf("SIZE OF trans array %d",countArr);
   // printf("%d",isValidAccount(&ptr));
    //recieveTransactionData(&ppp);
  ////  getTransactionAmount(&p);
  ////  isAmountAvailable(&p);
   // isBelowMaxAmount(&p);


    return 0;
}
