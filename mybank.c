#include "mybank.h"
#include<stdio.h>
#include <string.h>

/*
*  open an acount in
*/ 
void O (float accounts [2][50],float amount)
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
        success=0;
        printf("Failed opening new account\n");
    }
    printf("New account number is: %d\n",i+901);
    success = 1;
}
void B (float accounts [2][50],int account_number)
{
    if(account_number<901 || account_number >950 )
    {
        printf("Not in Range of accounts\n");
        success = 0;
        return;
    }
    if(accounts[0][account_number-901]==1)
    {
        printf("The balance of account number %d is: %f\n",account_number,accounts[1][account_number-901]);
        success = 1;
    }
    else
    {
        printf(" This account is closed\n");
        success = 0;
    }
}

void D (float accounts [2][50],int account_number,float amount)
{
    if(account_number<901 || account_number >950 )
    {
        printf("Not in Range of accounts.\n");
        success = 0;
        return;
    }
    if(amount<=0)
    {
        printf("Incorrent amount to deposit, must be positive float.\n");
        success=0;
        return;
    }
    if(accounts[0][account_number-901]==1)
    {
        accounts[1][account_number-901] += amount;
         printf("The balance of account number %d is: %f\n",account_number,accounts[1][account_number-901]);
        success = 1;
    }
    else
    {
        printf(" This account is closed\n");
        success = 0;
    }
    
}
void W (float accounts [2][50],int account_number,float amount)
{
    if(account_number<901 || account_number >950 )
    {
        printf("Not in Range of accounts.\n");
        success = 0;
        return;
    }
    if(amount<=0)
    {
        printf("Incorrent amount to deposit, must be positive float.\n");
        success=0;
        return;
    }
    if(accounts[0][account_number-901]==1)
    {
        if(amount <= accounts[1][account_number-901])
        {
            accounts[1][account_number-901] -= amount;
            printf("The balance of account number %d is: %f\n",account_number,accounts[1][account_number-901]);
            success = 1;
        }
        else
        {
            printf("Can't withdraw money since there isn't enough.\n");
            success=0;
        }
    }
    else
    {
        printf(" This account is closed\n");
        success = 0;
    }
}

void C (float accounts [2][50],int account_number)
{
    if(account_number<901 || account_number >950 )
    {
        printf("Not in Range of accounts.\n");
        success = 0;
        return;
    }
    if(accounts[0][account_number-901]==1)
    {
        accounts[1][account_number-901]=0;
        accounts[0][account_number-901]=0;
        success=1;
    }
    else
    {
        printf("This account is closed\n");
        success=0;
    }
}

void I (float accounts [2][50], int interest_rate)
{
    if(interest_rate>99 || interest_rate<-99)
    {
        success = 0;
        return;
    }
    float t = 1 + interest_rate/100.0;
    for(int i = 0;i<50;i++)
    {
        if(accounts[0][i]==1)
        {
            accounts[1][i]*=t;
        }
    }
    success=1;
}
void P(float accounts [2][50])
{
    for(int i = 0;i<50;i++)
    {
        if(accounts[0][i]==1)
        {
            printf("The balance of account number %d is: %f\n",i+901,accounts[1][i]);
        }
    }
}
void E(float accounts [2][50])
{
    bzero(accounts[0],50);
    bzero(accounts[1],50);
}


