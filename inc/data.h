#ifndef _DATA_H_
#define _DATA_H_

#include <stdint.h>

typedef struct
{
  uint8_t*      u8_data_ptr;
  uint16_t      u16_data_size;
  void          (*vfn_data_set_ptr)(void* data_ctx, uint8_t* in_u8_data, uint16_t in_data_size);
  void          (*vfn_data_set_bit)(void *data_ctx, uint16_t in_byte_index, uint8_t in_bit_index);
  void          (*vfn_data_reset_bit)(void *data_ctx, uint16_t in_byte_index, uint8_t in_bit_index);
  uint8_t       (*u8fn_data_get_bit)(void *data_ctx, uint16_t in_byte_index, uint8_t in_bit_index);
  uint8_t       (*u8fn_data_get_byte)(void *data_ctx, uint16_t in_byte_index);
  void          (*vfn_data_update_byte)(void *data_ctx, uint16_t in_byte_index, uint8_t in_byte_value);
  void          (*vfn_data_get_bytes)(void *data_ctx, uint8_t* out_data, uint16_t in_byte_start_index, uint16_t in_byte_size);
  void          (*vfn_data_update_bytes)(void *data_ctx, uint8_t* in_data, uint16_t in_byte_start_index, uint16_t in_byte_size);
} st_data_ctx_t;

void vfn_data_init(void *data_ctx);
#endif
