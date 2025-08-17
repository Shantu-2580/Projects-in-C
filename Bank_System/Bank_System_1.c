#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNumber;
    char name[50];
    float balance;
};

// Function prototypes
void createAccount();
void deposit();
void withdraw();
void checkBalance();
void displayAccounts();

int main() {
    int choice;

    while (1) {
        printf("\n==== Banking System Menu ====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: checkBalance(); break;
            case 5: displayAccounts(); break;
            case 6:
                printf("Thank you for using our banking system!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void createAccount() {
    FILE *fp;
    struct Account acc;

    fp = fopen("accounts.dat", "ab"); // append binary
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nEnter account number: ");
    scanf("%d", &acc.accNumber);
    printf("Enter account holder name: ");
    scanf(" %[^\n]", acc.name);
    acc.balance = 0.0;

    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}

void deposit() {
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;
    float amount;

    fp = fopen("accounts.dat", "rb+");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    printf("\nEnter account number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.accNumber == accNo) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            acc.balance += amount;
            fseek(fp, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, fp);
            printf("Deposit successful! New Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Account not found!\n");

    fclose(fp);
}

void withdraw() {
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;
    float amount;

    fp = fopen("accounts.dat", "rb+");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    printf("\nEnter account number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.accNumber == accNo) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > acc.balance) {
                printf("Insufficient balance!\n");
            } else {
                acc.balance -= amount;
                fseek(fp, -sizeof(struct Account), SEEK_CUR);
                fwrite(&acc, sizeof(struct Account), 1, fp);
                printf("Withdrawal successful! New Balance: %.2f\n", acc.balance);
            }
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Account not found!\n");

    fclose(fp);
}

void checkBalance() {
    FILE *fp;
    struct Account acc;
    int accNo, found = 0;

    fp = fopen("accounts.dat", "rb");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    printf("\nEnter account number: ");
    scanf("%d", &accNo);

    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.accNumber == accNo) {
            printf("Account Holder: %s\n", acc.name);
            printf("Balance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Account not found!\n");

    fclose(fp);
}

void displayAccounts() {
    FILE *fp;
    struct Account acc;

    fp = fopen("accounts.dat", "rb");
    if (fp == NULL) {
        printf("No accounts found!\n");
        return;
    }

    printf("\n==== All Accounts ====\n");
    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        printf("Account Number: %d\n", acc.accNumber);
        printf("Name: %s\n", acc.name);
        printf("Balance: %.2f\n\n", acc.balance);
    }

    fclose(fp);
}
