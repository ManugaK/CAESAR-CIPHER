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