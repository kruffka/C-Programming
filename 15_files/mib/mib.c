#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_NOF_MIB 64

typedef enum scs {
    scs15or60 = 0,
    scs30or120
} scs_e;

// заполнить и выставить сколько бит занимает поле
// https://www.sharetechnote.com/html/5G/5G_Mib_Sib.html MIB ::= SEQUENCE
/*
MIB ::= SEQUENCE {
    systemFrameNumber                   BIT STRING (SIZE (6)), => 6 bits
    subCarrierSpacingCommon             ENUMERATED {scs15or60, scs30or120}, => 1 bit
    ssb-SubcarrierOffset                INTEGER (0..15), => 4 bits
    dmrs-TypeA-Position                 ENUMERATED {pos2, pos3},  => 1 bit
    pdcch-ConfigSIB1                    INTEGER (0..255), => 8 bits
    cellBarred                          ENUMERATED {barred, notBarred},  => 1 bit
    intraFreqReselection                ENUMERATED {allowed, notAllowed}, => 1 bit
    spare                               BIT STRING (SIZE (1)) => 1 bit

} */
typedef struct MIB {
    
} MIB_t;

typedef struct MIB_LIST {
    int nof_mibs;
    MIB_t mib[MAX_NOF_MIB];
} MIB_LIST_t;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: ./mib bin_file\n");
        exit(1);
    }

    MIB_LIST_t *mib_list;
    
    // считать из бинарного файла байты и выяснить значения полей структуры
    FILE *file = fopen(argv[0], "rb");
    if (file == NULL) {
        printf("Error reading file\n");
        exit(1);
    }

    // Для каждого mib вывести несколько полей из структуры
    printf("nof_mibs is %d\n", mib_list->nof_mibs); // mib_list->mib[i].systemFrameNumber ?
}