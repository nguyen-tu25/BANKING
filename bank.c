#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ACCOUNT_NUM 20
#define MAX_ACCOUNTS 2


// Define a structure for an account
typedef struct {
    char fname[MAX_ACCOUNT_NUM];
    char lname[MAX_ACCOUNT_NUM];
    double balance;
    bool canUndo; // Flag to check if the last transaction can be undone
    double lastTransactionAmount; // Amount of the last transaction
} Account;

// Function to create a new account
Account createAccount(Account accounts[], int index) {
    // strcpy(account->accountNumber, accountNumber);
    printf("\n===CREATE ACCOUNT===");
    
    printf("\nFirst Name: ");
    scanf("%s", &accounts[index].fname);
    
    printf("\nLast Name: ");
    scanf("%s", &accounts[index].lname);
    
    printf("\nBalance: ");
    scanf("%lf", &accounts[index].balance);
    
    accounts[index].canUndo = false; // Initialize canUndo to false
    
    return accounts[index];
}

// Function to display an account
void displayAccount(Account account) {
    printf("\n===ACCOUNT DETAILS===\n");
    printf("First Name: %s\n", account.fname);
    printf("Last Name: %s\n", account.lname);
    printf("Balance: %.2f\n", account.balance);
}

// Function to deposit money into an account
void deposit(Account *account)
{
    double amount;
    printf("\nEnter amount you want to add into your account: ");
    scanf("%lf", &amount);
    if (amount > 0)
    {
        account->canUndo = true;
        account->lastTransactionAmount = amount;
        account->balance += amount;
        printf("Deposited %.2f into account %s %s\n", amount, account->fname, account->lname);
    }
    else
    {
        printf("Invalid deposit amount.\n");
    }
}

// Function to withdraw money from an account
void withdraw(Account* account)
{
    double amount;
    printf("\nEnter amount you want to withdraw: ");
    scanf("%lf", &amount);

    if (amount > 0 && account->balance >= amount)
    {
        account->canUndo = true;
        account->lastTransactionAmount = amount;
        account->balance -= amount;
        printf("Withdrawn %.2f from account %s %s\n", amount, account->fname, account->lname);
    }
    else
    {
        printf("Insufficient balance or invalid withdrawal amount.\n");
    }
}


void undoWithdraw(Account* account)
{
    if (account->canUndo == true)
    {
        account->balance += account->lastTransactionAmount;
        account->canUndo = false;
        printf("\nUndo successful: %.2f added back to account %s %s\n", account->lastTransactionAmount, account->fname, account->lname);
    }
    else
    {
        printf("\nNo transaction to undo.\n");
    }
}

void undoDeposit(Account* account)
{
    if (account->canUndo == true)
    {
        account->balance -= account->lastTransactionAmount;
        account->canUndo = false;
        printf("\nUndo successful: %.2f back to account %s %s\n", account->lastTransactionAmount, account->fname, account->lname);
    }
    else
    {
        printf("\nNo transaction to undo.\n");
    }
}

// Function to check account balance
void checkBalance(Account* account) {
    printf("Account %s %s balance: %.2f\n", account->fname, account->lname, account->balance);
}


int main()
{
    int choice;
    int accountIndex;
    Account accounts[MAX_ACCOUNTS]; // Array to store multiple accounts
    int numAccounts = 0; // Number of accounts created
    printf("\nWELCOME TO BANK ACCOUNT SYSTEM\n");

    do {
        printf("\n1.... CREATE A BANK ACCOUNT");
        printf("\n2.... DEPOSIT");
        printf("\n3.... WITHDRAW");
        printf("\n4.... UNDO DEPOSIT");
        printf("\n5.... UNDO WITHDRAW");
        printf("\n6.... CHECK BALANCE");

        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        
        // If the operation requires an account, ask for the account index
        if (choice > 1 && choice < 7)
        {
            printf("\nEnter account index (0 to %d): ", numAccounts - 1);
            scanf("%d", &accountIndex);
            // Validate selected account index
            if (accountIndex < 0 || accountIndex >= numAccounts) 
            {
                printf("Invalid account index.\n");
                continue; // Skip the rest of the loop iteration
            }
        }
        
        switch (choice) {
        case 1:
            if (numAccounts <= MAX_ACCOUNTS) {
                createAccount(accounts, numAccounts);
                displayAccount(accounts[numAccounts]);
                numAccounts++;
            }
            else
            {
                printf("Maximum number of accounts reached.\n");
            }
            break;
        case 2:
            deposit(&accounts[accountIndex]);
            displayAccount(accounts[accountIndex]);
            break;
        case 3:
            withdraw(&accounts[accountIndex]);
            displayAccount(accounts[accountIndex]);
            break;
        case 4:
            undoDeposit(&accounts[accountIndex]);
            displayAccount(accounts[accountIndex]);
            break;
        case 5: 
            undoWithdraw(&accounts[accountIndex]);
            displayAccount(accounts[accountIndex]);
            break;
        case 6:
            checkBalance(&accounts[accountIndex]);
            break;
        case 7:
            printf("\nGoodbye!!!");
            break;
        }
    } while(choice != 7);

    return 0;
}

