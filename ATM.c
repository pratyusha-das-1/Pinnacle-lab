#include <stdio.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    float amount;
} Transaction;

typedef struct {
    char name[30];
    int accountNumber;
    float balance;
    int pin;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} User;

User users[MAX_USERS];
int userCount = 0;

void initializeUsers();
int authenticateUser(int accountNumber, int pin);
void checkBalance(User *user);
void withdraw(User *user);
void deposit(User *user);
void transferFunds(User *user);
void addTransaction(User *user, char *description, float amount);
void displayTransactionHistory(User *user);
void showMenu(User *user);

int main() {
    int accountNumber, pin, userIndex;
    initializeUsers();

    printf("Welcome to the ATM!\n");
    printf("Enter your account number: ");
    scanf("%d", &accountNumber);
    printf("Enter your PIN: ");
    scanf("%d", &pin);

    userIndex = authenticateUser(accountNumber, pin);
    if (userIndex != -1) {
        showMenu(&users[userIndex]);
    } else {
        printf("Authentication failed! Please try again.\n");
    }

    return 0;
}

void initializeUsers() {
    strcpy(users[0].name, "Anand Pal");
    users[0].accountNumber = 123456;
    users[0].balance = 1000.0;
    users[0].pin = 1111;
    users[0].transactionCount = 0;
    userCount++;

    strcpy(users[1].name, "Jasmine Roy");
    users[1].accountNumber = 654321;
    users[1].balance = 2000.0;
    users[1].pin = 2222;
    users[1].transactionCount = 0;
    userCount++;
}

int authenticateUser(int accountNumber, int pin) {
    for (int i = 0; i < userCount; i++) {
        if (users[i].accountNumber == accountNumber && users[i].pin == pin) {
            return i;
        }
    }
    return -1;
}

void checkBalance(User *user) {
    printf("Current balance: $%.2f\n", user->balance);
}

void withdraw(User *user) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > user->balance) {
        printf("Insufficient funds!\n");
    } else {
        user->balance -= amount;
        addTransaction(user, "Withdraw", -amount);
        printf("Withdrawal successful! New balance: $%.2f\n", user->balance);
    }
}

void deposit(User *user) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    user->balance += amount;
    addTransaction(user, "Deposit", amount);
    printf("Deposit successful! New balance: $%.2f\n", user->balance);
}

void transferFunds(User *user) {
    int targetAccountNumber;
    float amount;
    int targetIndex = -1;

    printf("Enter account number to transfer to: ");
    scanf("%d", &targetAccountNumber);
    printf("Enter amount to transfer: ");
    scanf("%f", &amount);

    for (int i = 0; i < userCount; i++) {
        if (users[i].accountNumber == targetAccountNumber) {
            targetIndex = i;
            break;
        }
    }

    if (targetIndex == -1) {
        printf("Target account not found!\n");
    } else if (amount > user->balance) {
        printf("Insufficient funds!\n");
    } else {
        user->balance -= amount;
        users[targetIndex].balance += amount;
        addTransaction(user, "Transfer out", -amount);
        addTransaction(&users[targetIndex], "Transfer in", amount);
        printf("Transfer successful! New balance: $%.2f\n", user->balance);
    }
}

void addTransaction(User *user, char *description, float amount) {
    if (user->transactionCount < MAX_TRANSACTIONS) {
        strcpy(user->transactions[user->transactionCount].description, description);
        user->transactions[user->transactionCount].amount = amount;
        user->transactionCount++;
    } else {
        printf("Transaction history is full!\n");
    }
}

void displayTransactionHistory(User *user) {
    printf("Transaction history:\n");
    for (int i = 0; i < user->transactionCount; i++) {
        printf("%s: $%.2f\n", user->transactions[i].description, user->transactions[i].amount);
    }
}

void showMenu(User *user) {
    int choice;
    do {
        printf("\n--- ATM Menu ---\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw\n");
        printf("3. Deposit\n");
        printf("4. Transfer Funds\n");
        printf("5. Transaction History\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance(user);
                break;
            case 2:
                withdraw(user);
                break;
            case 3:
                deposit(user);
                break;
            case 4:
                transferFunds(user);
                break;
            case 5:
                displayTransactionHistory(user);
                break;
            case 6:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);
}

