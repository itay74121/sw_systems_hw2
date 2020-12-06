#include "mybank.h"
#include<stdio.h>
#include <string.h>

/*
*  open an acount in
*/ 
void O (double accounts [2][50],double amount)
{
    int i = 0;
    for(;i<50;i++)
    {
        if (accounts[0][i]==0)
        {
            accounts[0][i]=1;
            accounts[1][i]=amount;
            break;
        }
    }
    if(i==50)
    {
           printf("Failed opening new account\n");
    }
    printf("New account number is: %d \n",i+901);
}
void B (double accounts [2][50],int account_number)
{
    printf("The balance of account number %d is: %.2lf\n",account_number,accounts[1][account_number-901]);
}

void D (double accounts [2][50],int account_number,double amount)
{
    accounts[1][account_number-901] += amount;
    printf("The new balance is: %.2lf\n",accounts[1][account_number-901]);
}
void W (double accounts [2][50],int account_number,double amount)
{
    accounts[1][account_number-901] -= amount;
    printf("The new balance is: %.2lf\n",accounts[1][account_number-901]);
}

void C (double accounts [2][50],int account_number)
{
    accounts[1][account_number-901]=0;
    accounts[0][account_number-901]=0;
    printf("Closed account number %d\n",account_number);
}

void I (double accounts [2][50], int interest_rate)
{
    double t = 1 + interest_rate/100.0;
    for(int i = 0;i<50;i++)
    {
        if(accounts[0][i]==1)
        {
            accounts[1][i]*=t;
        }
    }
}
void P(double accounts [2][50])
{
    for(int i = 0;i<50;i++)
    {
        if(accounts[0][i]==1)
        {
            printf("The balance of account number %d is: %.2lf\n",i+901,accounts[1][i]);
        }
    }
}
void E(double accounts [2][50])
{
    bzero(accounts[0],50);
    bzero(accounts[1],50);
}


