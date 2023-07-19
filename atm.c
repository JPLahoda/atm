//Jason Lahoda, 2/26/2023, CIS2107
//Lab 3 ATM Machine
//This program is an ATM machine for a specific user to perform ATM operations.

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define PIN 3014
int balance = 5000;
int transactions = 0;

bool validAmountWithdraw(int amount) {
    
    if (amount <= 0 || amount % 20 != 0) {
        return false;
    }
    return true;
    
}

bool validAmountDeposit(int amount) {
    
    if (amount <= 0 || amount % 1 != 0) {
        return false;
    }
    return true;
    
}

void validPin(int input) {
    
    static int attempts = 3;
    while (attempts != 0){
        if (input == PIN) {
            return;
        } else {
            attempts--;
            printf("Invalid PIN. You have %d attempts remaining.\n", attempts);
            if (attempts == 0) {
                printf("You are out of attempts. Exiting program.\n");
                exit(0);
            }
            puts("Please enter a valid PIN.");
            scanf("%d", &input);
        }
    }
    
}

void receipt() {
    
    int choice;
    printf("Would you like a receipt?\n");
    printf("1: Yes\n");
    printf("2: No\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Receipt was printed.\n");
    } else {
        printf("Receipt was not printed.\n");
    }
    
}

void currentBalance() {
    
    printf("Your current balance is $%d.\n", balance);
    receipt();
    transactions++;
    
}

void withdraw() {
    
    int amount;
    printf("Please enter the withdraw amount to recieve in $20 bills: ");
    scanf("%d", &amount);
    if (!validAmountWithdraw(amount)) {
        printf("Invalid amount. Please only enter a valid amount to recieve in $20 bills.");
        return;
    }
    if (amount > 1000) {
        printf("Withdrawal limit exceeded. Maximum withdrawal amount is $1000.\n");
        return;
    }
    if (amount > balance) {
        printf("Insufficient balance. Your current balance is $%d.\n", balance);
        return;
    }
    balance -= amount;
    printf("Transaction successful. Your new balance is $%d.\n", balance);
    receipt();
    transactions++;
    
}

void deposit() {
    
    int amount;
    printf("Enter the amount to deposit: ");
    scanf("%d", &amount);
    if (!validAmountDeposit(amount)) {
        printf("Invalid amount. Please enter a valid amount; no change will be given.\n");
        return;
    }
    if (amount > 10000) {
        printf("Deposit limit exceeded. The maximum deposit amount is $10000.\n");
        return;
    }
    balance += amount;
    printf("Transaction was successful. Your new balance is $%d.\n", balance);
    receipt();
    transactions++;
    
}

int main() {
    
    int choice;
    int input;
    bool condition = true;

    printf("Welcome to the ATM machine.\n");
    printf("Please enter your PIN: ");
    scanf("%d", &input);
    validPin(input);
    while (condition) {
        printf("\n");
        printf("Select an option:\n");
        printf("1: Balance inquiry\n");
        printf("2: Cash withdrawal\n");
        printf("3: Cash deposit\n");
        printf("4: Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                currentBalance();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                deposit();
                break;
            case 4:
                printf("Thank you. You made %d transactions. Have a nice day.\n", transactions);
                condition = false;
                break;
            default:
                printf("That was not a valid choice.\n");
                break;
                
        }
    }
    exit(0);
}