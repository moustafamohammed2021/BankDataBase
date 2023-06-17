#include <stdio.h>
#include <stdlib.h>
#include "BankDataBase.h"
Coustomer_t Customer_Arr[5];
int counter;
int main()
{   char Choice;
    int Id_Check;
    double Money;
    int Id_From;
    int Id_To;
    while(1){
        printf("Please select The Following Options :\n\n");
        printf("1-Create a New Customer (Press 1 to Select This Option)\n");
        printf("2-Edit  Customer (Press 2 to Select This Option)\n");
        printf("3-Transfer Money From Customer to Another (Press 3 to Select This Option)\n");
        printf("4-Delete Customer (Press 4 to Select This Option)\n");
        printf("5-print Customer (Press 5 to Select This Option)\n");
        printf("6-Exit (Press 6 to Select This Option)\nEnter Your Choice :");
        fflush(stdin);
        scanf("%c",&Choice);
        printf("\n\n");

    switch(Choice){
        case '1':
            if(counter >=5){
                printf("The Max Number of The Customers is 5 you Can not Enter Any more\n");
                break;
            }
            vCreateNewCustomer();
         break;
        case '2':
            printf("Please Enter The Id Customer That you Want To edit it:");
            scanf("%i",&Id_Check);
            vEditCustomer(Id_Check);
            break;
        case '3':
            printf("Please Enter The Id Customer You Want To Transfer From:");
            scanf("%i",&Id_From);
            printf("Please Enter The Id Customer You Want To Transfer To:");
            scanf("%i",&Id_To);
            printf("The Money That You Want To Transfer:");
        L1:scanf("%lf",&Money);
            if(Money < 0){
                printf("The Money Should Be Greater Than Or Equal To Zero");
                goto L1;
            }
            vTransferMoney(Id_From,Id_To,Money);
         break;
        case '4':
            printf("Enter The Customer Id You Want To Delete It:");
            scanf("%i",&Id_Check);
            DeleteCustomerData(Id_Check);
            break;
        case '5':
            printf("Enter The Customer Id You Want To print his Information:");
            scanf("%i",&Id_Check);
            vPrintCustomerData(Id_Check);
         break;
        case '6':
            exit(0);
            break;
        default:
            printf("Wrong Input");
        }
    }
    return 0;
}
