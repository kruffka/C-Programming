#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

// Порядок байт: в сети числа передают в big-endian (network byte order),
// а наши машины (x86, ARM) держат их в little-endian. Отсюда htonl/ntohl.

void print_bytes(const char *label, uint32_t value) {
    const unsigned char *bytes = (const unsigned char *)&value;
    printf("%s = 0x%08X, байты в памяти:", label, value);
    for (int i = 0; i < 4; i++) {
        printf(" %02X", bytes[i]);
    }
    printf("\n");
}

int main(void) {

    uint32_t number = 0x12345678;

    printf("одно и то же число в разном порядке байт:\n");
    print_bytes("host             ", number);
    print_bytes("network (htonl)  ", htonl(number));
    print_bytes("обратно (ntohl)  ", ntohl(htonl(number)));

    return 0;
}
