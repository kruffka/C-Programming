#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "cipher_defs.h"
#include "stream_eea0.h"
#include "stream_eea1.h"
#include "stream_eea2.h"
#include "snow3g.h"

void stream_compute_encrypt(eea_alg_id_e alg, stream_cipher_t const* stream_cipher, uint8_t* out)
{
  if (alg == EEA0_ALG_ID) {
    printf("[INFO] EEA0 algorithm applied for encryption\n");
    stream_encrypt_eea0(stream_cipher, out);
  } else if (alg == EEA1_128_ALG_ID) {
    printf("[INFO] EEA1 algorithm applied for encryption\n");
    stream_encrypt_eea1(stream_cipher, out);
  } else if (alg == EEA2_128_ALG_ID) {
    printf("[INFO] EEA2 algorithm applied for  encryption\n");
    stream_encrypt_eea2(stream_cipher, out);
  }
}

stream_security_context_t *stream_ciphering_init(int ciphering_algorithm, const uint8_t *ciphering_key)
{
  switch (ciphering_algorithm) {
    case EEA0_ALG_ID: return NULL;
    case EEA1_128_ALG_ID: return stream_ciphering_init_eea1(ciphering_key);
    case EEA2_128_ALG_ID: return stream_ciphering_init_eea2(ciphering_key);
    default: printf("unsupported ciphering algorithm\n");
  }
}

void stream_ciphering_free(int ciphering_algorithm, stream_security_context_t *ciphering_context)
{
  switch (ciphering_algorithm) {
    case EEA0_ALG_ID: return;
    case EEA1_128_ALG_ID: return stream_ciphering_free_eea1(ciphering_context);
    case EEA2_128_ALG_ID: return stream_ciphering_free_eea2(ciphering_context);
    default: printf("unsupported ciphering algorithm\n");
  }
}

stream_security_container_t *stream_security_container_init(int ciphering_algorithm,
                                                            const uint8_t *ciphering_key)
{
  stream_security_container_t *container = calloc(1, sizeof(*container));
  assert(container != NULL);

  container->ciphering_algorithm = ciphering_algorithm;
  container->ciphering_context = stream_ciphering_init(ciphering_algorithm, ciphering_key);

  return container;
}

void stream_security_container_delete(stream_security_container_t *container)
{
  stream_ciphering_free(container->ciphering_algorithm, container->ciphering_context);
  free(container);
}
