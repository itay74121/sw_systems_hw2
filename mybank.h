#ifndef MY_BANK_H
#define MY_BANK_H
int success;
void O (float accounts [2][50],float amount);
void B (float accounts [2][50] , int account_number);
void D (float accounts [2][50], int account_number,float amount);
void W (float accounts [2][50], int account_number,float amount);
void C (float accounts [2][50], int account_number);
void I (float accounts [2][50], int interest_rate);
void P(float accounts [2][50]);
void E(float accounts [2][50]);

#endif