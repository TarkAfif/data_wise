#include <stdio.h>
#include <stdlib.h>

#include "data.h"

#define cst_data_max_size  32

st_data_ctx_t st_data_;
uint8_t data_test[cst_data_max_size];
void print_data_set(uint8_t* dataptr, uint16_t size);

int main()
{
    uint8_t cmd = 0;
    static uint8_t bittestfield_byte = 0, bittestfield_bit = 0;
    static uint8_t tempodata[cst_data_max_size] = {};
    vfn_data_init(&st_data_);
    st_data_.vfn_data_set_ptr(&st_data_, data_test, cst_data_max_size);
    while(1)
    {
        printf("Hello get cmd \n 1: set bit \n 2: reset bit \n 3: get bit \n 4: set byte \n 5: get byte \n 6: get amount data \n 7: update amount data \n ");
        if(scanf("%s", &cmd))
        {
            printf("\n");
            switch (cmd)
            {
            case '1': // set bit
                printf("Set bit command please set byte index ");
                scanf("%u", &bittestfield_byte); printf("\n");
                printf("Set bit command please set bit index ");
                scanf("%u", &bittestfield_bit); printf("\n");
                st_data_.vfn_data_set_bit(&st_data_,bittestfield_byte,bittestfield_bit);
                printf("byte: %u bit %u \n", bittestfield_byte, bittestfield_bit);
                break;
            case '2': // reset bit
                printf("Set bit command please set byte index ");
                scanf("%u", &bittestfield_byte); printf("\n");
                printf("Set bit command please set bit index ");
                scanf("%u", &bittestfield_bit); printf("\n");
                st_data_.vfn_data_reset_bit(&st_data_,bittestfield_byte,bittestfield_bit);
                printf("byte: %u bit: %u \n", bittestfield_byte, bittestfield_bit);
                break;
            case '3': // get bit
                printf("Set bit command please set byte index ");
                scanf("%u", &bittestfield_byte); printf("\n");
                printf("Set bit command please set bit index ");
                scanf("%u", &bittestfield_bit); printf("\n");
                printf("byte: %u bit %u value: %u \n", bittestfield_byte, bittestfield_bit, st_data_.u8fn_data_get_bit(&st_data_,bittestfield_byte,bittestfield_bit));
                break;
            case '4': //set byte
                printf("Set bit command please set byte index ");
                scanf("%u", &bittestfield_byte); printf("\n");
                printf("Set bit command please set byte value ");
                scanf("%u", &bittestfield_bit); printf("\n");
                st_data_.vfn_data_update_byte(&st_data_,bittestfield_byte,bittestfield_bit);
                printf("byte: %u bit: %u \n", bittestfield_byte, bittestfield_bit);
                break;
            case '5': // get byte
                printf("Set bit command please set byte index ");
                scanf("%u", &bittestfield_byte); printf("\n");
                printf("byte: %u value: %u \n", bittestfield_byte, st_data_.u8fn_data_get_byte(&st_data_,bittestfield_byte));
                break;
            case '6': // get amount data
                // Get data start index
                printf("Set data start index ");
                scanf("%u", &bittestfield_byte); printf("\n");
                // Get data size
                printf("Set data size ");
                scanf("%u", &bittestfield_bit); printf("\n");
                // Get data

                st_data_.vfn_data_get_bytes(&st_data_,tempodata, bittestfield_byte, bittestfield_bit );
                // print data
                print_data_set(tempodata,cst_data_max_size);
                break;
            case '7': // set amount data
                // Get data start index
                printf("Set data start index ");
                scanf("%u", &bittestfield_byte); printf("\n");
                // Get data size
                printf("Set data size ");
                scanf("%u", &bittestfield_bit); printf("\n");
                // Get data
                for(int index = 0; index < (bittestfield_bit - bittestfield_byte); index ++)
                {scanf("%u", (tempodata + index)); printf("\n");}
                // Update data set
                st_data_.vfn_data_update_bytes(&st_data_,tempodata, bittestfield_byte, bittestfield_bit );
                // print data
                print_data_set(tempodata,cst_data_max_size);
                break;
            default: // do nothing
                printf("hello dummy ! \n");
                break;
            }
            cmd = 0;
        }
        printf("\n");
        print_data_set(data_test,cst_data_max_size);
    }
    return 0;
}

void print_data_set(uint8_t* dataptr, uint16_t size)
{
    printf("Printing data set\n");
    for(int index = 0; index < size; index++)
    {
        printf(" %x ", dataptr[index]);
    }
    printf("end printing data set \n");
}
