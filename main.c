#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "caesar_cipher.h"

char queue[SIZE];
int front = 0;

// Initialize the circular queue with A–Z
void initQueue() {
    for (int i = 0; i < SIZE; i++) {
        queue[i] = 'A' + i;
    }
}

// Encrypt a single character
char encryptChar(char ch, int key) {
    if (!isalpha(ch)) return ch;

    ch = toupper(ch);
    int pos = (ch - 'A' + key + SIZE) % SIZE;
    return queue[pos];
}

// Decrypt a single character
char decryptChar(char ch, int key) {
    if (!isalpha(ch)) return ch;

    ch = toupper(ch);
    int pos = (ch - 'A' - key + SIZE) % SIZE;
    return queue[pos];
}

// Encrypt full message
void encrypt(char *message, int key, char *result) {
    for (int i = 0; message[i] != '\0'; i++) {
        result[i] = encryptChar(message[i], key);
    }
    result[strlen(message)] = '\0';
}

// Decrypt full message
void decrypt(char *message, int key, char *result) {
    for (int i = 0; message[i] != '\0'; i++) {
        result[i] = decryptChar(message[i], key);
    }
    result[strlen(message)] = '\0';
}

int main() {
    char choice;
    char message[1000], result[1000];
    int key;

    initQueue();

    printf("Encryption (E) or Decryption (D)?: ");
    scanf(" %c", &choice);
    getchar(); // clear newline

    if (choice == 'E' || choice == 'e') {
        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';

        printf("Enter shift key: ");
        scanf("%d", &key);

        encrypt(message, key, result);
        printf("***********\n");
        printf("Encrypted Message: %s\n", result);
    }
    
    else if (choice == 'D' || choice == 'd') {
        printf("Enter encrypted message: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';

        printf("Enter shift key: ");
        scanf("%d", &key);

        decrypt(message, key, result);
        printf("***********\n");
        printf("Original Message: %s\n", result);
    }

    
    else {
        printf("Invalid choice. Please enter 'E' or 'D'.\n");
    }

    return 0;
}