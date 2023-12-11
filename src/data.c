#include "data.h"

/*************************************************************************************
                                Bit wise functions
*************************************************************************************/
uint8_t u8fn_data_get_bit(void *data_ctx, uint16_t in_byte_index, uint8_t in_bit_index)
{
    st_data_ctx_t *data = (st_data_ctx_t *)data_ctx;
    if((in_byte_index > data->u16_data_size) || (in_bit_index >= 8)) return 0;
    return (*(data->u8_data_ptr + in_byte_index) >> in_bit_index) & 1;
}
void vfn_data_reset_bit(void *data_ctx, uint16_t in_byte_index, uint8_t in_bit_index)
{
    st_data_ctx_t *data = (st_data_ctx_t *)data_ctx;
    if((in_byte_index > data->u16_data_size) || (in_bit_index >= 8)) return;
    *(data->u8_data_ptr + in_byte_index) &= ~(1<<in_bit_index);
}

void vfn_data_set_bit(void *data_ctx, uint16_t in_byte_index, uint8_t in_bit_index)
{
    st_data_ctx_t *data = (st_data_ctx_t *)data_ctx;
    if((in_byte_index > data->u16_data_size) || (in_bit_index >= 8)) return;
    *(data->u8_data_ptr + in_byte_index) |= (1<<in_bit_index);
}

/*************************************************************************************
                                Byte wise functions
*************************************************************************************/
uint8_t u8fn_data_get_byte(void *data_ctx, uint16_t in_byte_index)
{
    st_data_ctx_t *data = (st_data_ctx_t *)data_ctx;
    if(in_byte_index > data->u16_data_size) return 0;
    return *(data->u8_data_ptr + in_byte_index);
}

void vfn_data_update_byte(void *data_ctx, uint16_t in_byte_index, uint8_t in_byte_value)
{
    st_data_ctx_t *data = (st_data_ctx_t *)data_ctx;
    if(in_byte_index > data->u16_data_size) return;
    *(data->u8_data_ptr + in_byte_index) = in_byte_value;
}

/*************************************************************************************
                                Amount of data wise functions
*************************************************************************************/
void vfn_data_get_bytes(void *data_ctx, uint8_t* out_data, uint16_t out_byte_start_index, uint16_t out_byte_size)
{
    st_data_ctx_t *data = (st_data_ctx_t *)data_ctx;
    if((out_byte_start_index + out_byte_size) > data->u16_data_size) return;
    for(uint16_t index = out_byte_start_index ; index < (out_byte_start_index + out_byte_size); index++)
    {
        *(out_data + index - out_byte_start_index) = *(data->u8_data_ptr + index);
    }
}

void vfn_data_update_bytes(void *data_ctx, uint8_t* in_data, uint16_t in_byte_start_index, uint16_t in_byte_size)
{
    st_data_ctx_t *data = (st_data_ctx_t *)data_ctx;
    if((in_byte_start_index + in_byte_size) > data->u16_data_size) return;
    for(uint16_t index = in_byte_start_index ; index < (in_byte_start_index + in_byte_size); index++)
    {
        *(data->u8_data_ptr + index) = *(in_data + index - in_byte_start_index);
    }
}

/*************************************************************************************
                                Set data pointer function
*************************************************************************************/
void vfn_data_set_ptr(void *data_ctx, uint8_t *in_u8_data, uint16_t in_data_size)
{
    st_data_ctx_t *data = (st_data_ctx_t *)data_ctx;
    data->u8_data_ptr = in_u8_data;
    data->u16_data_size = in_data_size;
}

/*************************************************************************************
                                Init lib function
*************************************************************************************/
void vfn_data_init(void *data_ctx)
{
    st_data_ctx_t *data = (st_data_ctx_t *)data_ctx;
    /* Set data pointer function */
    data->vfn_data_set_ptr = vfn_data_set_ptr;
    /* Bit wise functions */
    data->vfn_data_set_bit = vfn_data_set_bit;
    data->vfn_data_reset_bit = vfn_data_reset_bit;
    data->u8fn_data_get_bit = u8fn_data_get_bit;
    /* Byte wise functions */
    data->u8fn_data_get_byte = u8fn_data_get_byte;
    data->vfn_data_update_byte = vfn_data_update_byte;
    /* Amount of data wise functions */
    data->vfn_data_get_bytes = vfn_data_get_bytes;
    data->vfn_data_update_bytes = vfn_data_update_bytes;
}
