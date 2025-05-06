#ifndef CAESAR_CIPHER_H
#define CAESAR_CIPHER_H

#define SIZE 26

// Circular Queue & Character-level Encryption
void initQueue();
char encryptChar(char ch, int key);
char decryptChar(char ch, int key);

//Full massage processing
void encrypt(char *message, int key, char *result);
void decrypt(char *message, int key, char *result);


#endif
