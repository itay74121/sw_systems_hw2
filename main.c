#include "mybank.h"
#include <stdio.h>


void menu()
{
    char str [] = "\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit";
    printf("%s\n",str);
}

int main()
{
    char c;
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

        switch (c)
        {
        case 0:
            printf("\nInvalid transaction type\n");
            break;
        case 'O':
            printf("Please enter amount for deposit: ");
            status = scanf("%f%c",&amount,&t);
            if (status==0)
               printf("Failed to read the amount\n");
            if(status==2)
                O(accounts,amount);
            break;
        case 'B':
            printf("Please enter amount for deposit: ");
            status = scanf("%d%c",&account,&t);
            if(status == 0)
                printf("Failed to read the acount number\n");
            if(status==2)
            {
                B(accounts, account);
            }
            break;
        case 'D':
            printf("Please enter account number and amount: ");
            status = scanf("%d %f%c",&account,&amount,&t);
            if(status!=3)
                printf("Failed reading acount or amount number\n");
            else
            {
                D(accounts,account,amount);
            }
            break;
        case 'W':
            printf("Please enter account number and amount: ");
            status = scanf("%d %f%c",&account,&amount,&t);
            if(status!=3)
                printf("Failed reading account or amount numebr\n");
            else
            {
                W(accounts,account,amount);
            }
            break;
        case 'C':
            printf("Please enter account number: ");
            status = scanf("%d%c",&account,&t);
            if(status == 0)
               printf("Failed reading acount or amount number\n");
            if(status==2)
            {
                C(accounts, account);
            }
            break;
        case 'I':
            printf("Please enter account number: ");
            status = scanf("%f",&amount);
            if(status==0)
                printf("Failed reading interest rate\n");
            if(status==2)
            {
                I(accounts,amount);
            }
            break;
        case 'P':
            P(accounts);
            scanf("%c",&t);
            break;
        case 'E':
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

