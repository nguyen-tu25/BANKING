#include "account.h"
#include <stdio.h>

#define MAX_ACCOUNTS 2

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
        printf("\n7.... TRANSFER MONEY BETWEEN 2 ACCOUNTS");
        printf("\n8.... EXIT");

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
            if (numAccounts > 1) {
                int fromIndex, toIndex;
                printf("\nEnter the index of the account to transfer from (0 to %d): ", numAccounts - 1);
                scanf("%d", &fromIndex);
                printf("\nEnter the index of the account to transfer to (0 to %d): ", numAccounts - 1);
                scanf("%d", &toIndex);
                
                // Validate selected account indices
                if (fromIndex >= 0 && fromIndex < numAccounts && toIndex >= 0 && toIndex < numAccounts && fromIndex != toIndex)
                {
                    transferMoney(&accounts[fromIndex], &accounts[toIndex]);
                }
                else
                {
                    printf("Invalid account indices or same account selected.\n");
                }
            }
            else
            {
                printf("Not enough accounts to perform a transfer.\n");
            }
            break;
        case 8:
            printf("\nGoodbye!!!");
            break;
        }
    } while(choice != 8);

    return 0;
}