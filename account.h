#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdbool.h>

#define MAX_ACCOUNT_NUM 20


typedef struct
{
	char 	fname[MAX_ACCOUNT_NUM];
	char 	lname[MAX_ACCOUNT_NUM];
	double 	balance;
	bool 	canUndoWithdraw; // Flag to check if the last transaction (withdraw)
	bool	canUndoDeposit; // Flag to check if the last transaction (deposit)
	double 	lastTransactionAmount; // Amount of the last transaction
} Account;


Account createAccount(Account accounts[], int index);
void displayAccount(Account account);
void deposit(Account *account);
void withdraw(Account* account);
void undoWithdraw(Account* account);
void undoDeposit(Account* account);
void transferMoney(Account* fromAccount, Account* toAccount);
void checkBalance(Account* account);

#endif // ACCOUNT_H
