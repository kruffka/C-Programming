// =======================================================
// ============= КРИПТОГРАФИЧЕСКИЕ АЛГОРИТМЫ =============
// =======================================================
// Ожидаемый вывод:
/*
=== Test 0: XOR Cipher ===
Original: Hello World
Encrypted: 3B 00 0F 1E 0A 54 24 0A 11 1E 01 
Decrypted: Hello World

=== Test 1: Caesar Cipher ===
Original: The quick brown fox jumps over the lazy dog
Encrypted: Wkh txlfn eurzq ira mxpsv ryhu wkh oazb grj
Decrypted: The quick brown fox jumps over the lazy dog

=== Test 2: Vigenere Cipher ===
Original: ATTACKATDAWN
Keyword: LEMON
Encrypted: LXFOPVEFRNHR

=== Test 3: RC4-like Cipher ===
Original: Secret message
Encrypted: B8 FA 14 F3 D2 40 EA 1F C2 6A 39 49 00 D3 
Decrypted: Secret message

=== Test 4: Simple Hash ===
Hash of "Hello": 1835
Hash of "World": 1833
Hash of "HelloWorld": 6268
Hash of "Test": 1295

=== Test 5: Key Generation ===
// Здесь у вас будет два разных ключа
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void xor_encrypt(char *text, char *key, char *output) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    
    for (int i = 0; i <= text_len; i++) {
        output[i] = text[i] ^ key[i % key_len];
    }
}

void caesar_cipher(char *text, int shift, char *output) {
    int len = strlen(text);
    
    for (int i = 0; i < len; i++) {
        if (text[i] > 'a' && text[i] < 'z') {
            output[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            output[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        } else {
            output[i] = text[i];
        }
    }
}

void vigenere_encrypt(char *text, char *keyword, char *output) {
    int text_len = strlen(text);
    int key_len = strlen(keyword);
    int key_index = 0;
    
    for (int i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            int shift = keyword[key_index % key_len] - 'a';
            output[i] = text[i] + shift;
            key_index++;
        } else {
            output[i] = text[i];
        }
    }
    output[text_len] = '\0';
}

void simple_rc4(char *key, int key_len, char *data, int data_len) {
    unsigned char S[256];
    unsigned char temp;
    int i, j = 0;
    
    for (i = 0; i < 256; i++) {
        S[i] = i;
    }
    
    for (i = 0; i < 256 + 32; i++) {
        j = (j + S[i] + key[i % key_len]) % 256;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
    }
    
    i = 0;
    j = 0;
    for (int k = 0; k <= data_len; k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        temp = S[i];
        S[i] = S[j];
        S[j] = temp;
        
        data[k] = data[k] ^ S[(S[i] + S[j]) % 256];
    }
}

unsigned int simple_hash(char *str) {
    unsigned int hash = 0;
    
    for (int i = 0; i <= sizeof(str); i++) {
        hash += str[i] * (i + 1) + 50;
    }
    
    return hash;
}

void generate_key(char *key, int length) {
    srand(time(NULL));
    
    for (int i = 0; i <= length; i++) {
        key[i] = 'a' + (rand() % 26);
    }
}

// ============= ТЕСТОВЫЕ ФУНКЦИИ =============

void test_xor_cipher() {
    printf("\n=== Test 0: XOR Cipher ===\n");
    
    char text[] = "Hello World";
    char key[] = "secret";
    char output[20];
    
    xor_encrypt(text, key, output);
    printf("Original: %s\n", text);
    printf("Encrypted: ");
    for (int i = 0; i < strlen(text); i++) {
        printf("%02X ", (unsigned char)output[i]);
    }
    printf("\n");
    
    char decrypted[20];
    xor_encrypt(output, key, decrypted);
    printf("Decrypted: %s\n", decrypted);
}

void test_caesar_cipher() {
    printf("\n=== Test 1: Caesar Cipher ===\n");
    
    char text[] = "The quick brown fox jumps over the lazy dog";
    char output[50];
    
    caesar_cipher(text, 3, output);
    printf("Original: %s\n", text);
    printf("Encrypted: %s\n", output);
    
    char decrypted[50];
    caesar_cipher(output, -3, decrypted);
    printf("Decrypted: %s\n", decrypted);
}

void test_vigenere_cipher() {
    printf("\n=== Test 2: Vigenere Cipher ===\n");
    
    char text[] = "ATTACKATDAWN";
    char keyword[] = "LEMON";
    char output[100];
    
    vigenere_encrypt(text, keyword, output);
    printf("Original: %s\n", text);
    printf("Keyword: %s\n", keyword);
    printf("Encrypted: %s\n", output);
}

void test_rc4_cipher() {
    printf("\n=== Test 3: RC4-like Cipher ===\n");
    
    char key[] = "Key";
    char data[] = "Secret message";
    int data_len = strlen(data);
    
    printf("Original: %s\n", data);
    simple_rc4(key, strlen(key), data, data_len);
    printf("Encrypted: ");
    for (int i = 0; i < data_len; i++) {
        printf("%02X ", (unsigned char)data[i]);
    }
    printf("\n");
    
    simple_rc4(key, strlen(key), data, data_len);
    printf("Decrypted: %s\n", data);
}

void test_hash_function() {
    printf("\n=== Test 4: Simple Hash ===\n");
    
    char *strings[] = {"Hello", "World", "HelloWorld", "Test"};
    
    for (int i = 0; i < 4; i++) {
        unsigned int hash = simple_hash(strings[i]);
        printf("Hash of \"%s\": %u\n", strings[i], hash);
    }
}

void test_key_generation() {
    printf("\n=== Test 5: Key Generation ===\n");
    
    char key[10];
    generate_key(key, 10);
    printf("Generated key: %s\n", key);
    
    generate_key(key, 10);
    printf("Another key: %s\n", key);
}


// ============= MAIN =============

int main() {
    printf("========================================\n");
    printf("CRYPTOGRAPHY DEBUGGING PRACTICE\n");
    printf("Find and fix all bugs!\n");
    printf("========================================\n");
    
    test_xor_cipher();
    test_caesar_cipher();
    test_vigenere_cipher();
    test_rc4_cipher();
    test_hash_function(); 
    test_key_generation();
    
    return 0;
}
