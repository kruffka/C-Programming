
#include "cipher_defs.h"

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "aes.h"

// AES
// Обязательно:
// bearer < 32
// direction < 2
// blength > 7
void stream_encrypt_eea2(stream_cipher_t const *stream_cipher, uint8_t *out)
{
  // заглушка под aes
  aes128(stream_cipher, out);
}

stream_security_context_t *stream_ciphering_init_eea2(const uint8_t *ciphering_key)
{
  void *ret = calloc(1, 16);
  assert(ret != NULL);
  memcpy(ret, ciphering_key, 16);
  return (stream_security_context_t *)ret;
}

void stream_ciphering_free_eea2(stream_security_context_t *ciphering_context)
{
  free(ciphering_context);
}
