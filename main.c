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
    double amount;
    int status;
    int count=0;
    double accounts [2][50] = {{0},{0}};
    while(c!='E')
    {
        menu();
        do
        {
            scanf("%c",&c);
            }
        while (c=='\n' || c==0);
        switch (c)
        {
            case 0:
                printf("Invalid transaction type\n");
                break;
            case 'O':
                if (count==50)
                {
                    printf("There is no more space for accounts\n");
                    break;
                }
                printf("Please enter amount for deposit: ");
                status = scanf("%lf",&amount);
                if (status!=1)
                {
                    printf("Failed to read the amount\n");
                    break;
                }   
                if(amount<0)
                {
                    printf("Invalid Amount\n");
                    break;
                }
                O(accounts,amount);
                count++;
                break;
            case 'B':
                printf("Please enter account number: ");
                status = scanf("%d",&account);
                if(status != 1)
                {
                    printf("Failed to read the account number\n");
                    break;
                }
                if(account>950 || account<901)
                {
                    printf("Invalid account number\n");
                    break;
                }
                if(accounts[0][account-901]!=1)
                {
                    printf("This account is closed\n");
                    break;
                }
                B(accounts,account);
                break;
            case 'D':
                printf("Please enter account number: ");
                status = scanf("%d",&account);
                if (status!=1)
                {
                    printf("Failed to read the account number\n");
                    break;
                }
                if(account>950 || account<901)
                {
                    printf("Invalid account number\n");
                    break;
                }
                if(accounts[0][account-901]!=1)
                {
                    printf("This account is closed\n");
                    break;
                }
                printf("Please enter the amount to deposit: ");
                status = scanf("%lf",&amount);
                if(status!=1)
                {
                    printf("Failed to read the amount\n");
                    break;
                }
                if(amount<0)
                {
                    printf("Cannot deposit a negative amount\n");
                    break;
                }
                D(accounts,account,amount);
                break;
            case 'W':
                printf("Please enter account number: ");
                status = scanf("%d",&account);
                if(status!=1)
                {
                    printf("Failed to read the account number\n");
                    break;
                }
                if(account>950 || account<901)
                {
                    printf("Invalid account number\n");
                    break;
                }
                if(accounts[0][account-901]!=1)
                {
                    printf("This account is closed\n");
                    break;
                }
                printf("Please enter the amount to withdraw: ");
                status = scanf("%lf",&amount);
                if(status!=1)
                {
                    printf("Failed to read the amount\n");
                    break;
                }
                W(accounts,account,amount);
                break;
            case 'C':
                printf("Please enter account number: ");
                status = scanf("%d",&account);
                if(status != 1)
                {
                    printf("Failed to read the account number\n");
                    break;
                }
                if(account>950 || account<901)
                {
                    printf("Invalid account number\n");
                    break;
                }
                if(accounts[0][account-901]!=1)
                {
                    printf("This account is already closed\n");
                    break;
                }
                C(accounts,account);
                break;
            case 'I':
                printf("Please enter interest rate: ");
                status = scanf("%lf",&amount);
                if(status!=1)
                {
                    printf("Failed to read the interest rate\n");
                    break;
                }
                if(amount>99 || amount<-99)
                {
                    printf("Invalid interest rate\n");
                    break;
                }
                I(accounts,amount);
                break;
            case 'P':
                P(accounts);
                break;
            case 'E':
                E(accounts);
                c='E';
                break;  
            case '\n':
                break;
            default:
                printf("Invalid transaction type\n");
                break;
        }
    }
    return 0;
}

