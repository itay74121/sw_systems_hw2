#include "mybank.h"
#include <stdio.h>


void menu()
{
    char str [] = "\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit";
    printf("%s\n",str);
}
void lower(char * c)
{
    if(*c>='A' && *c<='Z')
    {
        *c -=  'A';
    }
}
int main()
{
    char c=0;
    char t;
    char * pc = &c;

    int account;
    float amount;
    int status;
    float accounts [2][50] = {{0},{0}};
    while(c!='E')
    {
        c=0;
        menu();
        printf("Enter transaction type: ");
        scanf("%c",&c);
        lower(pc);
        switch (c)
        {
        case 0:
            printf("\nInvalid transaction type\n");
            break;
        case 'o':
            printf("Please enter amount for deposit: ");
            status = scanf("%f%c",&amount,&t);
            if (status==0)
               printf("Failed to read the amount\n");
            if(status==2)
                O(accounts,amount);
            break;
        case 'b':
            printf("Please enter amount for deposit: ");
            status = scanf("%d%c",&account,&t);
            if(status == 0)
                printf("Failed to read the acount number\n");
            if(status==2)
            {
                B(accounts, account);
            }
            break;
        case 'd':
            printf("Please enter account number and amount: ");
            status = scanf("%d %f%c",&account,&amount,&t);
            if(status!=3)
                printf("Failed reading acount or amount number\n");
            else
            {
                D(accounts,account,amount);
            }
            break;
        case 'w':
            printf("Please enter account number and amount: ");
            status = scanf("%d %f%c",&account,&amount,&t);
            if(status!=3)
                printf("Failed reading account or amount numebr\n");
            else
            {
                W(accounts,account,amount);
            }
            break;
        case 'c':
            printf("Please enter account number: ");
            status = scanf("%d%c",&account,&t);
            if(status == 0)
               printf("Failed reading acount or amount number\n");
            if(status==2)
            {
                C(accounts, account);
            }
            break;
        case 'i':
            printf("Please enter account number: ");
            status = scanf("%f",&amount);
            if(status==0)
                printf("Failed reading interest rate\n");
            if(status==2)
            {
                I(accounts,amount);
            }
            break;
        case 'p':
            P(accounts);
            scanf("%c",&t);
            break;
        case 'e':
            E(accounts);
            c='E';
            break;   
        default:
          printf("\nInvalid transaction type\n");
        break;
        }
    }
    return 0;
}

