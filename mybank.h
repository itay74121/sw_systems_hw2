#ifndef MY_BANK_H
#define MY_BANK_H
/*Function to open a new account */
void O (double accounts [2][50],double amount);
/*Function to check the balance of an open account*/
void B (double accounts [2][50] , int account_number);
/*Function to add money in account */
void D (double accounts [2][50], int account_number,double amount);
/*Function to withdraw money from an account*/
void W (double accounts [2][50], int account_number,double amount);
/*Function to close an open account*/
void C (double accounts [2][50], int account_number);
/*Function to do an interest rate*/
void I (double accounts [2][50], int interest_rate);
/*Function to print all open accounts their balances.*/
void P(double accounts [2][50]);
/*Function to close all the accounts in the bank*/
void E(double accounts [2][50]);
#endif