#include "mybank.h"
#include<stdio.h>
#include <string.h>

/*
*  open an account with amount 
*/ 
void O (double accounts [2][50],double amount)
{
    int f = 0;
    int i =0;// init i as 0 
    for(;i<50;i++) //  loop through all account searching for an open space for account 
    {
        if (accounts[0][i]==0) // indicating closed account space ready to be used 
        {
            f=1;
            accounts[0][i]=1; // set it as an open account 
            accounts[1][i]=amount; // put amount inside 
            break; // stop the loop since we are done
        }
    }
    if(f==0) //check if looped through all and didn't find open space 
    {
           printf("Failed opening new account\n");
    }
    else  //otherwise print new account number 
        printf("New account number is: %d \n",i+901);
}
/**
 * function checks the amount of money
*/
void B (double accounts [2][50],int account_number)
{
    //printin the amount of money in the account number 
    printf("The balance of account number %d is: %.2lf\n",account_number,accounts[1][account_number-901]);
}
/**
 * Deposit amount of money into account 
*/
void D (double accounts [2][50],int account_number,double amount)
{
    // add the amount of money to the account 
    accounts[1][account_number-901] += amount;
    // print the new money amount in the account
    printf("The new balance is: %.2lf\n",accounts[1][account_number-901]);
}
/**
 * Withdraw money form an account 
*/
void W (double accounts [2][50],int account_number,double amount)
{
    // make sure that there is enough money in the account to make the withdraw 
    if (amount<=accounts[1][account_number-901])
    {
        // change the amount of money in the account 
        accounts[1][account_number-901] -= amount;
        // print the new amount of money of the account 
        printf("The new balance is: %.2lf\n",accounts[1][account_number-901]);
    }
    else // if there is not enough of money print this message 
    {
        printf("There is not enough money in the account for this withdrawl\n");
    }
    
}
/**
 * Close an account number 
*/
void C (double accounts [2][50],int account_number)
{
    // change amount of money to 0
    accounts[1][account_number-901]=0;
    // close the account officially 
    accounts[0][account_number-901]=0;
    //print the closed acount number 
    printf("Closed account number %d\n",account_number);
}
/**
 * calculate the interest rate for all of the accounts 
*/
void I (double accounts [2][50], int interest_rate)
{
    double t = 1 + interest_rate/100.0; // put in t the value to use for the interest rate 
    for(int i = 0;i<50;i++) // loop on all accounts 
    {
        if(accounts[0][i]==1) // check if account is opne 
        {
            accounts[1][i]*=t; // if so multiply t by the amount of money in it.
        }
    }
}
/**
 * Print all the open accounts and their balances 
*/
void P(double accounts [2][50])
{
    for(int i = 0;i<50;i++) // loop through accounts 
    {
        if(accounts[0][i]==1) // check if account 901+i is open 
        {
            // if so print account balance 
            printf("The balance of account number %d is: %.2lf\n",i+901,accounts[1][i]);
        }
    }
}
/**
 * Exit the program. close all of the accounts 
*/
void E(double accounts [2][50])
{
    // using the bzero function from string.h 
    // to set all values in  accounts to 0
    bzero(accounts[0],50); 
    bzero(accounts[1],50);
}