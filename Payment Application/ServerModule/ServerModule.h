#ifndef SERVERMODULE_H_INCLUDED
#include"../CardModule/CardModule.h"
#include"../TerminalModule/TerminalModule.h"
#define SERVERMODULE_H_INCLUDED

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;


typedef enum EN_transState_t
{
   APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transState_t transState;
    uint32_t transactionSequenceNumber;
}ST_transaction_t;

typedef struct ST_accountsDB_t
{
    float balance;
    uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

ST_accountsDB_t accountArray[10];




typedef enum EN_serverError_t
{
    ok, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t ;



EN_transState_t recieveTransactionData(ST_transaction_t *transData);
EN_serverError_t isValidAccount(ST_cardData_t *cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t *termData);
EN_serverError_t saveTransaction(ST_transaction_t *transData);
EN_cardError_t serverCheck(void);
//EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t *transData);


#endif // SERVERMODULE_H_INCLUDED