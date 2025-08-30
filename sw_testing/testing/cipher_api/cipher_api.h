#ifndef _CIPHER_API_H_
#define _CIPHER_API_H_

#include "cipher_defs.h"

void stream_compute_encrypt(eea_alg_id_e alg, stream_cipher_t const* stream_cipher, uint8_t* out);

stream_security_context_t *stream_ciphering_init(int ciphering_algorithm, const uint8_t *ciphering_key);

void stream_ciphering_free(int ciphering_algorithm, stream_security_context_t *ciphering_context);

stream_security_container_t *stream_security_container_init(int ciphering_algorithm,
    const uint8_t *ciphering_key);

void stream_security_container_delete(stream_security_container_t *container);

#endif // _CIPHER_API_H_