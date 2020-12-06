#include "mybank.h"
#include <stdio.h>

/*
The menue function prints the menue of operations to the screen.
*/
void menu()
{
    // create a string 
    char str [] = "\nPlease choose a transaction type:\n O-Open Account\n B-Balance Inquiry\n D-Deposit\n W-Withdrawal\n C-Close Account\n I-Interest\n P-Print\n E-Exit";
    printf("%s\n",str); // print the string to the string
}

int main()
{
    char c; // character to take input 
    int account; // account variable to take input 
    double amount; // amount variable input to take 
    int status; // status to take input from 
    int count=0; // represents the number of open accounts in bank 
    double accounts [2][50] = {{0},{0}};
    while(c!='E')
    {
        menu(); // print the menue
        do // take input using do while 
        {
            scanf("%c",&c);
        }
        while (c=='\n' || c==0); // take input aslong as it's \n or \0
        switch (c) // switch case 
        {
            case 0: // test case \0 for EOF
                printf("Invalid transaction type\n"); 
                break;
            case 'O': // test case to Open function 
                if (count==50) // if there is no space no account can be opened
                {
                    printf("There is no more space for accounts\n");
                    break;
                }
                printf("Please enter amount for deposit: "); // take a deposit 
                status = scanf("%lf",&amount); // take input double from user
                if (status!=1) // if failed to take input 
                {
                    printf("Failed to read the amount\n"); // print to the screen failed message and break 
                    break;
                }   
                if(amount<0)
                {
                    // if the amount taken by the user is negative it means it's an invalid amount
                    printf("Invalid Amount\n");
                    break;
                }
                // if all of the above is ok we may continue to the O function 
                O(accounts,amount); 
                count++; // add one to the open acoounts and break
                break;
            case 'B': // test case for Birur function 
                // ask for a an account from the user and take it as an integer input 
                printf("Please enter account number: ");
                status = scanf("%d",&account);
                if(status != 1) // check if failed to take integer input 
                {
                    // if so print to the screen a message indicating that
                    printf("Failed to read the account number\n"); 
                    break;
                }
                if(account>950 || account<901) // check that the account number iven by the user is in the range 
                {
                    // if not print a message to the screnn to let them know and break from this case
                    printf("Invalid account number\n");
                    break;
                }
                if(accounts[0][account-901]!=1) // check if the account is open 
                {
                    // let the user know that the account is closed and break the case
                    printf("This account is closed\n");
                    break;
                }
                // if all of the above is fine proceed to the B function 
                B(accounts,account); 
                break;
            case 'D': // test case for D function 
                // take as input from the user an account number 
                printf("Please enter account number: ");
                status = scanf("%d",&account);
                if (status!=1) // check if input taking failed 
                {
                    // print to the screen a message indicating about failiure and break
                    printf("Failed to read the account number\n");
                    break;
                }
                if(account>950 || account<901) //check if account is not in desired 
                {
                    // if the account number is not in desired range print a messsage indicating of that and break
                    printf("Invalid account number\n");
                    break;
                }
                if(accounts[0][account-901]!=1) //  check if the account is closed
                {
                    // if so print a message indicating that the account is closed and break
                    printf("This account is closed\n");
                    break;
                }
                // take as input from the user for mount to deposit 
                printf("Please enter the amount to deposit: ");
                status = scanf("%lf",&amount);
                if(status!=1) // check f failed to take input 
                {
                    // if so print a message indicating of that and break
                    printf("Failed to read the amount\n");
                    break;
                }
                if(amount<0) // check if the amount given is not negative 
                {
                    // if so print a message indicating of that and break 
                    printf("Cannot deposit a negative amount\n");
                    break;
                }
                // if all of the above is ok call function D and break
                D(accounts,account,amount); 
                break;
            case 'W': // test case for W function 
                // take input an account number to withddraw from 
                printf("Please enter account number: "); 
                status = scanf("%d",&account);
                if(status!=1) // cehck if failed to take input 
                {
                    // if so print message indicating of that and break 
                    printf("Failed to read the account number\n");
                    break;
                }
                if(account>950 || account<901) // check if account number is not in desired range 
                {
                    // if so print a message to the to let them know that the number is not in range and break
                    printf("Invalid account number\n");
                    break;
                }
                if(accounts[0][account-901]!=1) // check if the account is closed 
                {
                    // if so print to the screen a message indicating of that and break 
                    printf("This account is closed\n");
                    break;
                }
                // take input for amount to withdraw
                printf("Please enter the amount to withdraw: ");
                status = scanf("%lf",&amount);
                if(status!=1)// if failed to take input 
                {
                    // if so print message to the screen saying that and break 
                    printf("Failed to read the amount\n");
                    break;
                }
                // call the W function and break 
                W(accounts,account,amount);
                break;
            case 'C': //C test case 
                // take as input account number 
                printf("Please enter account number: ");
                status = scanf("%d",&account);
                if(status != 1) // check if failed to take input 
                {
                    // if so print to screen
                    printf("Failed to read the account number\n");
                    break;
                }
                if(account>950 || account<901)// check if the account is not in desired range 
                {
                    // print a message indicating of that and break 
                    printf("Invalid account number\n");
                    break;
                }
                if(accounts[0][account-901]!=1) //  check if the account is cloed
                {
                    // if so print a message indicating of that and break 
                    printf("This account is already closed\n");
                    break;
                }
                C(accounts,account); // call the C function and break 
                break;
            case 'I': // test case I
                // take input for interest rate 
                printf("Please enter interest rate: ");
                status = scanf("%lf",&amount);
                if(status!=1) // check if failed to take input 
                {
                    // if so print a message to the screen and break 
                    printf("Failed to read the interest rate\n");
                    break;
                }
                if(amount>99 || amount<-99) // check if interest rate is not in desired range 
                {
                    // if so print a message of that and break 
                    printf("Invalid interest rate\n");
                    break;
                }
                // call the I function and break 
                I(accounts,amount);
                break;
            case 'P': // test P 
                P(accounts); // call function P and break 
                break;
            case 'E': // test E 
                E(accounts); // call function 
                c='E'; // change c to E
                break;   
            case '\n': // test case for incident \n 
                // basically do nothing
                break;
            default: // default case 
                // to take invalid commands and print this.
                printf("Invalid transaction type\n");
                break;
        }
    }
    return 0;
}

