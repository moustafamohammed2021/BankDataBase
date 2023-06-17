
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BankDataBase.h"
extern Coustomer_t Customer_Arr[5];
extern int counter;
/*Functions Definition of the system*/
void vCreateNewCustomer(void){
    Coustomer_t NewCustomer;//create New Customer from The Structure
    printf("Please Enter The Name of The Customer Number %i:",counter+1);
    fflush(stdin);//delete The Internal Buffer
    gets(NewCustomer.Name);//to store The name Of the Customer
   label:printf("\nPlease Enter The Cash Of The Customer Number %i:",counter+1);
    fflush(stdin);
    scanf("%lf",&(NewCustomer.Cash));//store The Customer cash From The user
    if(NewCustomer.Cash < 0){
        printf("The Cash Money should Be Greater Than or Equal To Zero\n");
        goto label;
    }
    printf("\nPlease Enter The Type of The Customer Number %i (Credit or Debit):",counter+1);
    fflush(stdin);
    gets(NewCustomer.Type);
    printf("\nPlease Enter The ID of The Customer Number %i:",counter+1);
    scanf("%i",&(NewCustomer.Id));
    printf("\n\n");
    Customer_Arr[counter]=NewCustomer;
    counter++;

}//For Creation New customer
void vEditCustomer(int Id ){
    int i;
    for(i=0;i<=counter;i++){
        if(Customer_Arr[i].Id==Id){
                /*Gets The new Name Of the Customer*/
            printf("Enter The New Name :");
            fflush(stdin);
            gets(Customer_Arr[i].Name);
            /*Gets The New cash Of the Customer */
            printf("Enter The New Cash :");
            scanf("%lf",&(Customer_Arr[i].Cash));
            /*Gets The new Type */
            printf("Enter The New Type (Credit of Debit) :");
            fflush(stdin);
            gets(Customer_Arr[i].Type);
            /*Gets the New id*/
            printf("Enter The New ID :");
            scanf("%i",&(Customer_Arr[i].Id));
            printf("\n\n");
            break;
        }
    }
}//for Edit The information Of the Customer
void vPrintCustomerData(int Id){
    int i;
    for(i=0;i<=counter;i++){
        if(Id==Customer_Arr[i].Id){
            printf("The Name of Customer Number %i is :%s\n",i+1,Customer_Arr[i].Name);
            printf("The Cash of Customer Number %i is :%0.2lf\n",i+1,Customer_Arr[i].Cash);
            printf("The Type of Customer Number %i is :%s\n",i+1,Customer_Arr[i].Type);
            printf("The ID   of Customer Number %i is :%i\n",i+1,Customer_Arr[i].Id);
            printf("\n\n");
            break;
        }
    }
}//For Print The Customer Data
void vTransferMoney(int SourceId ,int DestinationId,double Money){
    int i;
    int IndexFrom=-1;
    int IndexTo=-1;
    L1:for(i=0;i<=counter;i++){
            if(SourceId==Customer_Arr[i].Id){
                IndexFrom=i;
            }
            else if(DestinationId==Customer_Arr[i].Id){
                IndexTo=i;
            }
            if((IndexFrom!=-1) && (IndexTo !=-1)){
                break;
            }
    }
    if((IndexFrom==-1) || (IndexTo==-1)){
        printf("Please Enter Valid Id\n");
        goto L1;
    }
    if(Money > Customer_Arr[IndexFrom].Cash){
        printf("The Money Transfered Is Greater Than Your Cash \n");
        printf("Please Enter The Money Transfered Again");
        goto L1;
    }
    Customer_Arr[IndexFrom].Cash=Customer_Arr[IndexFrom].Cash-Money;
    Customer_Arr[IndexTo].Cash=Customer_Arr[IndexTo].Cash+Money;
}
void DeleteCustomerData(int Id ){
    int i;
    int Index;
    for(i=0;i<=counter-1;i++){
        if(Id==Customer_Arr[i].Id){
            Index=i;
            for(i=Index;i<=counter-1;i++){
                Customer_Arr[i]=Customer_Arr[i+1];
            }
            break;
        }
    }
    Customer_Arr[counter].Cash=-1;//Indication That The Cash Is Empty
    Customer_Arr[counter].Id=-1;//Indicate That The Empty Place
    strcpy(Customer_Arr[counter].Name,"-1");
    strcpy(Customer_Arr[counter].Type,"-1");
    counter--;
}
