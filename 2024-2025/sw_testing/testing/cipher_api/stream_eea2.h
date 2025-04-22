#ifndef STREAM_EEA2_H
#define STREAM_EEA2_H

#include "cipher_defs.h"

void stream_encrypt_eea2(stream_cipher_t const *stream_cipher, uint8_t *out);

stream_security_context_t *stream_ciphering_init_eea2(const uint8_t *ciphering_key);
void stream_ciphering_free_eea2(stream_security_context_t *ciphering_context);

#endif // STREAM_EEA2_H