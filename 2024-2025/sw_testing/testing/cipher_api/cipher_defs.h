#ifndef _STREAM_CIPHER_H_
#define _STREAM_CIPHER_H_

#include <stdint.h>
#include <string.h>

#define AUTH_KINT_SIZE 16

typedef enum {
  EEA0_ALG_ID = 0x00,
  EEA1_128_ALG_ID = 0x01,
  EEA2_128_ALG_ID = 0x02,

  END_EEA_ALG_ID
} eea_alg_id_e;


/* stream_security_context_t is an opaque structure.
 * It is different for each ciphering algorithm in use.
 * Defined as a struct to have compilation time type checking
 * (the "context" field is never actually used).
 */
typedef struct {
  void *context;
} stream_security_context_t;

/* stream_security_container_t contains the current configuration
 * of ciphering. It is used by PDCP and NAS.
 */
typedef struct {
  int ciphering_algorithm;
  stream_security_context_t *ciphering_context;
} stream_security_container_t;

typedef struct {
  stream_security_context_t *context;
  uint32_t count;
  uint8_t  bearer;
  uint8_t  direction;
  uint8_t  *message;
  /* length in bits */
  uint32_t blength;
} stream_cipher_t;

stream_security_context_t *stream_ciphering_init(int ciphering_algorithm, const uint8_t *ciphering_key);
void stream_ciphering_free(int ciphering_algorithm, stream_security_context_t *ciphering_context);

stream_security_container_t *stream_security_container_init(int ciphering_algorithm, const uint8_t *ciphering_key);
void stream_security_container_delete(stream_security_container_t *container);


#endif //_STREAM_CIPHER_H_