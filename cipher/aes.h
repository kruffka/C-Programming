#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>
#include "cipher_api/cipher_defs.h"

typedef enum {
    AES_INITIALIZATION_VECTOR_8,
    AES_INITIALIZATION_VECTOR_16,
    NONE_INITIALIZATION_VECTOR,
  
    AES_INITIALIZATION_VECTOR_END,
} iv_e;

// see 33.401 B.2.3 for the input to 128-EIA2
// (which is identical to 128-NIA2, see 33.501 D.3.1.3) 

typedef struct {
    uint32_t count;
    uint8_t padding: 2;
    uint8_t direction: 1;
    uint8_t bearer: 5;
    uint8_t pad_8;
    uint16_t pad_16;
    uint64_t pad_64;
} data_iv16_t;
  
typedef struct{
   union{
     data_iv16_t d;
     uint8_t iv[16];
   }; 
} iv16_t;
  
typedef struct {
    uint32_t count;
    uint8_t padding: 2;
    uint8_t direction: 1;
    uint8_t bearer: 5;
    uint8_t pad_8;
    uint16_t pad_16;
} data_iv8_t;
  
typedef struct{
   union{
     data_iv8_t d;
     uint8_t iv[8];
   }; 
} iv8_t;
  
typedef struct {
    uint8_t key[16];
    iv_e type;
    union{
      iv8_t iv8;
      iv16_t iv16;
    };
} aes_128_t;


void aes128(const stream_cipher_t *stream_cipher, uint8_t *out);
#endif // _AES_H_