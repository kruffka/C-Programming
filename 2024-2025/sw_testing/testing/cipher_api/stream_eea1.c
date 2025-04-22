#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "cipher_defs.h"
#include "stream_eea1.h"
#include "snow3g.h"

void stream_encrypt_eea1(stream_cipher_t const *stream_cipher, uint8_t *out)
{
  SNOW_CTX ctx;
  uint32_t zero_bit = 0;
  uint32_t byte_length;

  zero_bit = stream_cipher->blength & 0x7;
  byte_length = stream_cipher->blength >> 3;

  // Если длина сообщения не кратна 8 добавим байт в конец
  byte_length += ((zero_bit >> 3) + 1);

  // Вектора IV и K заполняются в SNOW_INIT
  SNOW_init(stream_cipher->count,
            stream_cipher->bearer,
            stream_cipher->direction,
            (const char *)stream_cipher->context,
            &ctx);

  /* Run SNOW 3G algorithm to generate sequence of key stream bits KS*/
  SNOW(byte_length, stream_cipher->message, out, &ctx);

  int ceil_index = 0;

  if (zero_bit > 0) {
      ceil_index = (stream_cipher->blength + 7) >> 3;
      out[ceil_index - 1] = out[ceil_index - 1] & (uint8_t)(0xFF << (8 - zero_bit));
  }
                   
}

stream_security_context_t *stream_ciphering_init_eea1(const uint8_t *ciphering_key)
{
  void *ret = calloc(1, 16);
  assert(ret != NULL);
  memcpy(ret, ciphering_key, 16);
  return (stream_security_context_t *)ret;
}

void stream_ciphering_free_eea1(stream_security_context_t *ciphering_context)
{
  free(ciphering_context);
}
