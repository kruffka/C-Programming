#include <stdio.h>
#include "aes.h"

// Заглушка вместо aes шифра
void aes128(const stream_cipher_t *stream_cipher, uint8_t *out) {
    (void)stream_cipher;
    (void)out;
    
    aes_128_t k_iv = {.type = NONE_INITIALIZATION_VECTOR};
    (void)k_iv;
}