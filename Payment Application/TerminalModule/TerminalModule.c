#include "TerminalModule.h"
#include<stdio.h>

ST_terminalData_t terminalinfo;
char chkexp =-1;
char chktransamount = -1;
char chktransbel = -1;
EN_terminalError_t getTransactionDate(ST_terminalData_t *termData){
    termData = &terminalinfo;
    int counter=0;
    char result =WRONG_DATE;
    while(result==WRONG_DATE){
        printf("please enter the Transaction date in the format dd/mm/yyyy\n");
        gets(termData->transactionDate);
        while((termData->transactionDate)[counter]!='\0'){
            counter++;
        }
        if(!(counter==0 || counter <10)){
            result = Ok;
            return result;
        }
    }
}



EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData){
    int cardMonth = (cardData.cardExpirationDate[0]) * 10 + cardData.cardExpirationDate[1];
	int cardYear = (cardData.cardExpirationDate[3] ) * 10 + cardData.cardExpirationDate[4] ;
	int transMonth = (termData.transactionDate[3] ) * 10 + termData.transactionDate[4] ;
	int transYear = (termData.transactionDate[8]) * 10+ +termData.transactionDate[9];
	if (transYear > cardYear) {
            printf("EXPIRED card\n");
		return EXPIRED_CARD;
	}
	if (transYear == cardYear && transMonth > cardMonth) {
	    printf("EXPIRED card\n");
		return EXPIRED_CARD;
	}
	else{
	    printf("Valid Card\n");
	return Ok;
	}
    /*

    if((cardData.cardExpirationDate[3]>=termData.transactionDate[8])&& (cardData.cardExpirationDate[4]>=termData.transactionDate[9])){
            //printf("sana TM nkhosh ala elshahr");
            if(cardData.cardExpirationDate[0]>=termData.transactionDate[3] && cardData.cardExpirationDate[1]>=termData.transactionDate[4]){
                    chkexp = Ok;
                    return Ok;
            }
    }
     else {
    return EXPIRED_CARD;
    }*/
}
EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData){
    termData=&terminalinfo;
   // char res=EXCEED_MAX_AMOUNT; //not sure
    char result = INVALID_AMOUNT;
    while(result== INVALID_AMOUNT ){
            printf("Please enter the transaction amount( Note:The amount must be more than 0)\n"); //and must be less than transactionMAXAMOUNT )\n");
            scanf("%f",&(termData->transAmount));
            if(!(termData->transAmount <=0)){
                result = Ok;
                chktransamount = Ok;
                return result;
            }
    }
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData){
    termData =& terminalinfo;
    termData->maxTransAmount =5000;
    if((termData->maxTransAmount) <=0){
            printf("Error maximum transaction amount must be more than zero\n");
        return INVALID_MAX_AMOUNT;
    }
    else {
          //  printf("Transaction is %.2f",termData->maxTransAmount);
            return Ok;
    }
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData){
    //printf("**********");
    termData =&terminalinfo;
    char result=EXCEED_MAX_AMOUNT;
    float ft,fm;
    while(result==EXCEED_MAX_AMOUNT){
    ft=termData->transAmount;
    fm= termData->maxTransAmount;
           // printf("****************\n");
           // printf("%.2f\n%.2f\n",termData->maxTransAmount,termData->transAmount);
    if(ft>fm){
       printf("Please enter transaction amount less than or equal to %.2f\n",fm);
       scanf("%f",&(termData->transAmount));
    }
    else{
        result =Ok;
        chktransbel = Ok;
        printf("%d",result);
        return result;

    }
 }
}
EN_terminalError_t terminalCheck(void){
    if((chkexp==Ok) && (chktransamount==Ok) && (chktransbel==Ok)){
        return Ok;
    }
    else{
        return Ok;
    }

}

