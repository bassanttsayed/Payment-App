#include"ServerModule.h"
#include<stdio.h>
#include<string.h>

extern ST_cardData_t cardinf;
extern ST_terminalData_t terminalinfo;
char index=-1;
char chkavlacc = -1;
char chkavlbal = -1;

ST_transaction_t transactionArray[255]={0};
int countArr =0;
char saveFlag = -1;


void initilizeDB(void){
    ST_accountsDB_t acc1  = {70000,"123456789bassantt"};
    ST_accountsDB_t acc2  = {5000,"00000022223333444"};
    ST_accountsDB_t acc3  = {400,"1234x1234x1234xxx"};
    ST_accountsDB_t acc4  = {10000,"4444bbbb4444bbbb"};
    ST_accountsDB_t acc5  = {8000,"12121212121212121"};
    ST_accountsDB_t acc6  = {8500,"mmm3kkk4j5hh67gui"};
    ST_accountsDB_t acc7  = {60000,"mn45d8w3f654984444"};
    ST_accountsDB_t acc8  = {20000,"1234x1234x1234zzz"};
    ST_accountsDB_t acc9  = {6000,"1234x8989v1234m6m6"};
    ST_accountsDB_t acc10 = {12000,"kkkkb1234ll444bnb"};
    accountArray[0] = acc1;
    accountArray[1] = acc2;
    accountArray[2] = acc3;
    accountArray[3] = acc4;
    accountArray[4] = acc5;
    accountArray[5] = acc6;
    accountArray[6] = acc7;
    accountArray[7] = acc8;
    accountArray[8] = acc9;
    accountArray[9] = acc10;
}
EN_serverError_t isValidAccount(ST_cardData_t *cardData){
    initilizeDB();
    cardData=&cardinf;
    char fcheck=0;
    for (int i=0; i<10; i++){
    if(!(strcmp((cardData->primaryAccountNumber),accountArray[i].primaryAccountNumber))){
        printf("The account is available\n");
        index=i;
        fcheck=1;
        chkavlacc = ok;
    //    avalAcc= ok;
        return ok;
    }
    else {
        fcheck=0;
    }
     if(i==9 && fcheck ==0){
        printf("Account is not found!\n");
      //  avalAcc = ACCOUNT_NOT_FOUND;
        chkavlacc = ACCOUNT_NOT_FOUND;
        return ACCOUNT_NOT_FOUND;
     }

    }
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData){
    termData=&terminalinfo;
    if(index!=-1){
        if((termData->transAmount)>accountArray[index].balance){
            printf("Your tansaction amount is more than your balance!\n");
             chkavlbal = LOW_BALANCE;
         //   avalBal = LOW_BALANCE;
            return LOW_BALANCE;
        }
        else {
            printf("Your transaction will proceed\n");
            chkavlbal = ok;
           // avalBal = ok;
            return ok;
        }
    }

}
EN_cardError_t serverCheck(void){
    if((chkavlacc==ok) && (chkavlbal==ok)){
        return ok;
    }
    else {
        return -1;
    }
}



EN_serverError_t saveTransaction(ST_transaction_t *transData){
  //  ST_cardData_t * cobj = &cardinf;
  //  ST_terminalData_t *tobj = &terminalinfo;
    transData = transactionArray;
    if((chkavlacc==ok) && (chkavlbal==ok)  && (cardCheck()==ok) &&(terminalCheck()==ok) && (serverCheck()==ok) ){
            if(countArr<255){
                strcpy((transData->cardHolderData.cardHolderName),(cardinf.cardHolderName));
                strcpy((transData->cardHolderData.primaryAccountNumber),(cardinf.primaryAccountNumber));
                strcpy((transData->cardHolderData.cardExpirationDate),(cardinf.cardExpirationDate));
                strcpy((transData->terminalData.transactionDate),(terminalinfo.transactionDate));
                transData->terminalData.transAmount=terminalinfo.transAmount;
                transData->terminalData.maxTransAmount= terminalinfo.maxTransAmount;
                transData->transactionSequenceNumber ++;
                transData->transState = APPROVED;
                //na2es datamember mahtet-hush bta3 transState
                transData ++;
                countArr++;
                saveFlag = ok;
                return ok;


            }
            else{
                    saveFlag= SAVING_FAILED;
                return SAVING_FAILED;
            }

    }
    else if ((chkavlacc==ok) && (chkavlbal==LOW_BALANCE) && (cardCheck()==ok) &&(terminalCheck()==ok) && (serverCheck()==ok)  ){

        if(countArr<255){
                strcpy((transData->cardHolderData.cardHolderName),(cardinf.cardHolderName));
                strcpy((transData->cardHolderData.primaryAccountNumber),(cardinf.primaryAccountNumber));
                strcpy((transData->cardHolderData.cardExpirationDate),(cardinf.cardExpirationDate));
                strcpy((transData->terminalData.transactionDate),(terminalinfo.transactionDate));
                transData->terminalData.transAmount=terminalinfo.transAmount;
                transData->terminalData.maxTransAmount= terminalinfo.maxTransAmount;
                transData->transactionSequenceNumber ++;
                transData->transState = DECLINED_INSUFFECIENT_FUND;
                //na2es datamember mahtet-hush bta3 transState
                transData ++;
                countArr++;
                saveFlag = ok;
                return ok;

        }
        else{
                saveFlag = SAVING_FAILED;
            return SAVING_FAILED;
        }
    }
    else{
            saveFlag = SAVING_FAILED;
        return SAVING_FAILED;
    }

}
EN_transState_t recieveTransactionData(ST_transaction_t *transData){
    if(chkavlacc==ACCOUNT_NOT_FOUND){
            printf("DECLINED STOLEN\n");
        return DECLINED_STOLEN_CARD;
    }
    if(chkavlbal==LOW_BALANCE){
                    printf("DECLINED low balance\n");
        return DECLINED_INSUFFECIENT_FUND;
    }
    if(saveFlag==SAVING_FAILED){
            printf("internal server error\n");
            return INTERNAL_SERVER_ERROR;
    }
    else{
            printf("Before the approval balance is %0.2f\n",(accountArray[index].balance));
        ((accountArray[index]).balance) = ((accountArray[index]).balance) - terminalinfo.transAmount;
     printf("After the approval balance is %0.2f\n",(accountArray[index].balance));
        return APPROVED;
    }

}


