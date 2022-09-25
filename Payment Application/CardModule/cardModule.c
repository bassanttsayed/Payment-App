#include"CardModule.h"
#include<stdio.h>

ST_cardData_t cardinf;
char chkname = -1;
char chkdate = -1;
char chknum = -1;
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {
    int counter;
    char result =WRONG_NAME;

	cardData = &cardinf;
	//char reserve [25];
	while(result ==WRONG_NAME){
            counter=0;
	    printf("Please enter the card holder name with 20-24 characters\n");
	   // cardData->cardHolderName ;
		gets(cardData->cardHolderName);
       // printf("%s\n",cardData->cardHolderName);

	while((cardData->cardHolderName)[counter] != '\0'){
            counter++;
	}
	printf("You entered %d characters \n",counter);

	if(!(counter<20 || counter> 24)){
        result =OK;
        printf("%d\n",result);
        chkname=result;
        printf("You entered characters in the desired range\n");
        return result;
	}

	}//
	//printf("****");
//counter >= 20 && counter <=24

	/*if(!(counter<20 || counter> 24)){
            result = OK;
            return result;
            printf("%d",result);
	}*/

	/*else{
        printf("The card holder name must be 20 min or at most 24");
        result = WRONG_NAME;
            printf("%d",result);
	}*/
}



EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData){

    cardData =&cardinf;
    int i=0;
    char result =WRONG_EXP_DATE;
    while(result ==WRONG_EXP_DATE){
        printf("please enter the Card expiry date in the format mm/yy\n");
        gets(cardData->cardExpirationDate);
        while((cardData->cardExpirationDate)[i]!='\0'){
            i++;
        }
        if(i!=0 && i<6){
          //if (((cardData->cardExpirationDate)[0]<'2') && ((cardData->cardExpirationDate)[0]>='0') && ((cardData->cardExpirationDate)[2]=='/') ) {
           // if(((cardData->cardExpirationDate)[1]>='0')&& ((cardData->cardExpirationDate)[1]<='9')){
            result = OK;
            chkdate=result;
            return result;
         // }
        //  }
        }
    }
   /* if(!(i=0 || i>5)){
        result = OK;
        return result;
    }*/
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData){
    cardData= &cardinf;
    int count;
    char result =WRONG_PAN;
    while(result ==WRONG_PAN){
            count =0;
        printf("Please enter the card PAN that is in the range 16-19 digits\n");
        gets(cardData->primaryAccountNumber);
        while((cardData->primaryAccountNumber)[count]!='\0'){
            count++;
        }
        printf("You entered %d digits\n",count);
        if(!(count<16 || count>19 )){
           result =OK;
           chknum =result;
    printf("Card PAN is in the desired format\n");
           return result;
        }
    }
      /* if(!(count<16 || count>19 )){
           result =OK;
           return result;
        }*/
}

EN_cardError_t cardCheck(void){
    if((chknum==OK) && (chkname==OK) && (chkdate==OK)){
        return OK;
    }
    else{
        return -1;
    }
}


