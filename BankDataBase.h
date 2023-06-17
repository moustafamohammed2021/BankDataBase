#ifndef BANK_DATA_BASE_H
#define BANK_DATA_BASE_H

/*Structure Definition For The Data of The The Customer*/
typedef struct {
    char Name[50];//String For The Name
    double Cash;//The Money in His cash
    char  Type[7];//type of his Cash Debit Or Credit
    int Id;//The Specific Id For only One customer
}Coustomer_t;

/*Functions Deceleration of the system*/
void vCreateNewCustomer(void);//For Creation New customer
void vEditCustomer(int Id );//for Edit The information Of the Customer
void vPrintCustomerData(int Id);//For Print The Customer Data
void vTransferMoney(int SourceId ,int DestinationId,double Money);
void DeleteCustomerData(int Id );
#endif // BANK_DATA_BASE_H
