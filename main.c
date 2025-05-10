#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "caesar_cipher.h"

char queue[SIZE]; // Circular queue to store A–Z


// Initialize the circular queue with A–Z
void initQueue() {
    for (int i = 0; i < SIZE; i++) {
        queue[i] = 'A' + i; // Fill the queue with A-Z
    }
}

// Encrypt a single character
char encryptChar(char ch, int key) {
    if (!isalpha(ch)) return ch; // Leave non-alphabetic characters unchanged

    ch = toupper(ch); // Convert to uppercase for uniform processing
    int pos = (ch - 'A' + key + SIZE) % SIZE; // Circular shift using modular arithmetic
    return queue[pos]; // Return encrypted character
}

// Decrypt a single character
char decryptChar(char ch, int key) {
    if (!isalpha(ch)) return ch; // Leave non-alphabetic characters unchanged

    ch = toupper(ch);
    int pos = (ch - 'A' - key + SIZE) % SIZE; // Reverse shift for decryption
    return queue[pos]; // Return decrypted character
}

// Encrypt the entire message string using caesar cipher
void encrypt(char *message, int key, char *result) {
    for (int i = 0; message[i] != '\0'; i++) {
        result[i] = encryptChar(message[i], key); // Encrypt each character
    }
    result[strlen(message)] = '\0';  // null- twrminate the result string
}

// Decrypt the entire message string using caesar cipher
void decrypt(char *message, int key, char *result) {
    for (int i = 0; message[i] != '\0'; i++) {
        result[i] = decryptChar(message[i], key); //Decrypt each character
    }
    result[strlen(message)] = '\0';  // null- twrminate the result string
}

int main() {
    char choice;  // User choice: E for encryption, D for decryption
    char message[1000];   // Original or encrypted input message
    char result[1000];    // Result after encryption or decryption
    int key;   // Shift key

    initQueue();   // Initialize the alphabet queue
  
    // Ask user for encryption or decryption mode
    printf("Encryption (E) or Decryption (D)?: ");
    scanf(" %c", &choice);
    getchar();   // Clear newline character from input buffer

    if (choice == 'E' || choice == 'e') {
        // Encryption mode
        printf("Enter your message: ");
        fgets(message, sizeof(message), stdin);  // Read message input
        message[strcspn(message, "\n")] = '\0';  // Remove newline

        printf("Enter shift key: ");
        scanf("%d", &key); // Read shift key

        encrypt(message, key, result);  // Call encryption function
        printf("***********\n");
        printf("Encrypted Message: %s\n", result);
    }
    
    else if (choice == 'D' || choice == 'd') {
        // Decryption mode
        printf("Enter encrypted message: ");
        fgets(message, sizeof(message), stdin);  // Read encrypted message
        message[strcspn(message, "\n")] = '\0'; // Remove newline

        printf("Enter shift key: ");
        scanf("%d", &key);   // Read shift key

        decrypt(message, key, result);   // Call decryption function
        printf("***********\n");
        printf("Original Message: %s\n", result);
    }

    
    else {
        // Invalid input
        printf("Invalid choice. Please enter 'E' or 'D'.\n");
    }

    return 0;
}
