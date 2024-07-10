#include "account.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a new account
Account createAccount(Account accounts[], int index) {
    // strcpy(account->accountNumber, accountNumber);
    printf("\n===CREATE ACCOUNT===");
    
    printf("\nFirst Name: ");
    scanf("%s", accounts[index].fname);
    
    printf("\nLast Name: ");
    scanf("%s", accounts[index].lname);
    
    printf("\nBalance: ");
    scanf("%lf", &accounts[index].balance);
    
    accounts[index].canUndoWithdraw = false; // Initialize canUndoWithdraw to false
	accounts[index].canUndoDeposit = false; // Initialize canUndoDeposit to false
    
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
        account->canUndoDeposit = true;
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
        account->canUndoWithdraw = true;
        account->lastTransactionAmount = amount;
        account->balance -= amount;
        printf("Withdrawn %.2f from account %s %s\n", amount, account->fname, account->lname);
    }
    else
    {
        printf("Insufficient balance or invalid withdrawal amount.\n");
    }
}

// Function to undo withdraw
void undoWithdraw(Account* account)
{
    if (account->canUndoWithdraw == true)
    {
        account->balance += account->lastTransactionAmount;
        account->canUndoWithdraw = false;
        printf("\nUndo withdraw successful: %.2f back to account %s %s\n", account->lastTransactionAmount, account->fname, account->lname);
    }
    else
    {
        printf("\nNo transaction to undo.\n");
    }
}

// Function to undo deposit
void undoDeposit(Account* account)
{
    if (account->canUndoDeposit == true)
    {
        account->balance -= account->lastTransactionAmount;
        account->canUndoDeposit = false;
        printf("\nUndo deposit successful: %.2f back to account %s %s\n", account->lastTransactionAmount, account->fname, account->lname);
    }
    else
    {
        printf("\nNo transaction to undo.\n");
    }
}

// Function to transfer money between two accounts
void transferMoney(Account *fromAccount, Account *toAccount) {
    double amount;
    printf("\nEnter amount you want to transfer: ");
    scanf("%lf", &amount);
    
    if (amount > 0 && fromAccount->balance >= amount) {
        fromAccount->balance -= amount;
        toAccount->balance += amount;
        printf("Transferred %.2f from account %s %s to account %s %s\n", amount, fromAccount->fname, fromAccount->lname, toAccount->fname, toAccount->lname);
    }
    else
    {
        printf("Insufficient balance or invalid transfer amount.\n");
    }
}

// Function to check account balance
void checkBalance(Account* account) {
    printf("Account %s %s balance: %.2f\n", account->fname, account->lname, account->balance);
}
