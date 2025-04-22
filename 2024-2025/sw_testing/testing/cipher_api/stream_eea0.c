#include "cipher_defs.h"

void stream_encrypt_eea0(stream_cipher_t const *stream_cipher, uint8_t *out)
{
  uint32_t byte_length = (stream_cipher->blength + 7) >> 3;
  memcpy(out, stream_cipher->message, byte_length);
}
