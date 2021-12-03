#ifndef LIBMODBUS_H
#define LIBMODBUS_H

/* Add this for macros that defined unix flavor */

#include "stdint.h"

#include <winsock2.h>
#pragma comment(lib,"WS2_32.lib")

//#if (defined(__unix__) || defined(unix)) && !defined(USG)
//#include <sys/param.h>
//#endif
//
//#ifndef _MSC_VER
//#include <stdint.h>
//#else
//#include "stdint.h"
//#endif
//
#include "LibModbus\LibModbus-Version.h"
#include "Public.h"
#include "CameraPara.h"

/* Modbus function codes */
#define MODBUS_FC_READ_COILS                0x01
#define MODBUS_FC_READ_DISCRETE_INPUTS      0x02
#define MODBUS_FC_READ_HOLDING_REGISTERS    0x03
#define MODBUS_FC_READ_INPUT_REGISTERS      0x04
#define MODBUS_FC_WRITE_SINGLE_COIL         0x05
#define MODBUS_FC_WRITE_SINGLE_REGISTER     0x06
#define MODBUS_FC_READ_EXCEPTION_STATUS     0x07
#define MODBUS_FC_WRITE_MULTIPLE_COILS      0x0F
#define MODBUS_FC_WRITE_MULTIPLE_REGISTERS  0x10
#define MODBUS_FC_REPORT_SLAVE_ID           0x11
#define MODBUS_FC_MASK_WRITE_REGISTER       0x16
#define MODBUS_FC_WRITE_AND_READ_REGISTERS  0x17

#define MODBUS_BROADCAST_ADDRESS            0

/* Modbus_Application_Protocol_V1_1b.pdf (chapter 6 section 1 page 12)
* Quantity of Coils to read (2 bytes): 1 to 2000 (0x7D0)
* (chapter 6 section 11 page 29)
* Quantity of Coils to write (2 bytes): 1 to 1968 (0x7B0)
*/
#define MODBUS_MAX_READ_BITS              2000
#define MODBUS_MAX_WRITE_BITS             1968

/* Modbus_Application_Protocol_V1_1b.pdf (chapter 6 section 3 page 15)
* Quantity of Registers to read (2 bytes): 1 to 125 (0x7D)
* (chapter 6 section 12 page 31)
* Quantity of Registers to write (2 bytes) 1 to 123 (0x7B)
* (chapter 6 section 17 page 38)
* Quantity of Registers to write in R/W registers (2 bytes) 1 to 121 (0x79)
*/
#define MODBUS_MAX_READ_REGISTERS          125
#define MODBUS_MAX_WRITE_REGISTERS         123
#define MODBUS_MAX_WR_WRITE_REGISTERS      121
#define MODBUS_MAX_WR_READ_REGISTERS       125

/* The size of the MODBUS PDU is limited by the size constraint inherited from
* the first MODBUS implementation on Serial Line network (max. RS485 ADU = 256
* bytes). Therefore, MODBUS PDU for serial line communication = 256 - Server
* address (1 byte) - CRC (2 bytes) = 253 bytes.
*/
#define MODBUS_MAX_PDU_LENGTH              253

/* Consequently:
* - RTU MODBUS ADU = 253 bytes + Server address (1 byte) + CRC (2 bytes) = 256
*   bytes.
* - TCP MODBUS ADU = 253 bytes + MBAP (7 bytes) = 260 bytes.
* so the maximum of both backend in 260 bytes. This size can used to allocate
* an array of bytes to store responses and it will be compatible with the two
* backends.
*/
#define MODBUS_MAX_ADU_LENGTH              260

/* Random number to avoid errno conflicts */
#define MODBUS_ENOBASE 112345678

/* Protocol exceptions */
enum {
	MODBUS_EXCEPTION_ILLEGAL_FUNCTION = 0x01,
	MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS,
	MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE,
	MODBUS_EXCEPTION_SLAVE_OR_SERVER_FAILURE,
	MODBUS_EXCEPTION_ACKNOWLEDGE,
	MODBUS_EXCEPTION_SLAVE_OR_SERVER_BUSY,
	MODBUS_EXCEPTION_NEGATIVE_ACKNOWLEDGE,
	MODBUS_EXCEPTION_MEMORY_PARITY,
	MODBUS_EXCEPTION_NOT_DEFINED,
	MODBUS_EXCEPTION_GATEWAY_PATH,
	MODBUS_EXCEPTION_GATEWAY_TARGET,
	MODBUS_EXCEPTION_MAX
};

#define EMBXILFUN  (MODBUS_ENOBASE + MODBUS_EXCEPTION_ILLEGAL_FUNCTION)
#define EMBXILADD  (MODBUS_ENOBASE + MODBUS_EXCEPTION_ILLEGAL_DATA_ADDRESS)
#define EMBXILVAL  (MODBUS_ENOBASE + MODBUS_EXCEPTION_ILLEGAL_DATA_VALUE)
#define EMBXSFAIL  (MODBUS_ENOBASE + MODBUS_EXCEPTION_SLAVE_OR_SERVER_FAILURE)
#define EMBXACK    (MODBUS_ENOBASE + MODBUS_EXCEPTION_ACKNOWLEDGE)
#define EMBXSBUSY  (MODBUS_ENOBASE + MODBUS_EXCEPTION_SLAVE_OR_SERVER_BUSY)
#define EMBXNACK   (MODBUS_ENOBASE + MODBUS_EXCEPTION_NEGATIVE_ACKNOWLEDGE)
#define EMBXMEMPAR (MODBUS_ENOBASE + MODBUS_EXCEPTION_MEMORY_PARITY)
#define EMBXGPATH  (MODBUS_ENOBASE + MODBUS_EXCEPTION_GATEWAY_PATH)
#define EMBXGTAR   (MODBUS_ENOBASE + MODBUS_EXCEPTION_GATEWAY_TARGET)

/* Native libmodbus error codes */
#define EMBBADCRC  (EMBXGTAR + 1)
#define EMBBADDATA (EMBXGTAR + 2)
#define EMBBADEXC  (EMBXGTAR + 3)
#define EMBUNKEXC  (EMBXGTAR + 4)
#define EMBMDATA   (EMBXGTAR + 5)
#define EMBBADSLAVE (EMBXGTAR + 6)

extern const unsigned int libmodbus_version_major;
extern const unsigned int libmodbus_version_minor;
extern const unsigned int libmodbus_version_micro;

typedef struct _modbus modbus_t;

typedef struct _modbus_mapping_t {
	int nb_bits;
	int start_bits;
	int nb_input_bits;
	int start_input_bits;
	int nb_input_registers;
	int start_input_registers;
	int nb_registers;
	int start_registers;
	uint8_t *tab_bits;
	uint8_t *tab_input_bits;
	uint16_t *tab_input_registers;
	uint16_t *tab_registers;
} modbus_mapping_t;

typedef enum
{
	MODBUS_ERROR_RECOVERY_NONE = 0,
	MODBUS_ERROR_RECOVERY_LINK = (1 << 1),
	MODBUS_ERROR_RECOVERY_PROTOCOL = (1 << 2)
} modbus_error_recovery_mode;

DLLAPI int STDCALL modbus_set_slave(modbus_t* ctx, int slave);
DLLAPI int STDCALL modbus_get_slave(modbus_t* ctx);
DLLAPI int STDCALL modbus_set_error_recovery(modbus_t *ctx, modbus_error_recovery_mode error_recovery);
DLLAPI int STDCALL modbus_set_socket(modbus_t *ctx, int s);
DLLAPI int STDCALL modbus_get_socket(modbus_t *ctx);

DLLAPI int STDCALL modbus_get_response_timeout(modbus_t *ctx, uint32_t *to_sec, uint32_t *to_usec);
DLLAPI int STDCALL modbus_set_response_timeout(modbus_t *ctx, uint32_t to_sec, uint32_t to_usec);

DLLAPI int STDCALL modbus_get_byte_timeout(modbus_t *ctx, uint32_t *to_sec, uint32_t *to_usec);
DLLAPI int STDCALL modbus_set_byte_timeout(modbus_t *ctx, uint32_t to_sec, uint32_t to_usec);

DLLAPI int STDCALL modbus_get_indication_timeout(modbus_t *ctx, uint32_t *to_sec, uint32_t *to_usec);
DLLAPI int STDCALL modbus_set_indication_timeout(modbus_t *ctx, uint32_t to_sec, uint32_t to_usec);

DLLAPI int STDCALL modbus_get_header_length(modbus_t *ctx);

DLLAPI int STDCALL modbus_connect(modbus_t *ctx);
DLLAPI void STDCALL modbus_close(modbus_t *ctx);

DLLAPI void STDCALL modbus_free(modbus_t *ctx);

DLLAPI int STDCALL modbus_flush(modbus_t *ctx);
DLLAPI int STDCALL modbus_set_debug(modbus_t *ctx, int flag);

DLLAPI const char* STDCALL modbus_strerror(int errnum);

DLLAPI int STDCALL modbus_read_bits(modbus_t *ctx, int addr, int nb, uint8_t *dest);
DLLAPI int STDCALL modbus_read_input_bits(modbus_t *ctx, int addr, int nb, uint8_t *dest);
DLLAPI int STDCALL modbus_read_registers(modbus_t *ctx, int addr, int nb, uint16_t *dest);
DLLAPI int STDCALL modbus_read_input_registers(modbus_t *ctx, int addr, int nb, uint16_t *dest);
DLLAPI int STDCALL modbus_write_bit(modbus_t *ctx, int coil_addr, int status);
DLLAPI int STDCALL modbus_write_register(modbus_t *ctx, int reg_addr, int value);
DLLAPI int STDCALL modbus_write_bits(modbus_t *ctx, int addr, int nb, const uint8_t *data);
DLLAPI int STDCALL modbus_write_registers(modbus_t *ctx, int addr, int nb, const uint16_t *data);
DLLAPI int STDCALL modbus_mask_write_register(modbus_t *ctx, int addr, uint16_t and_mask, uint16_t or_mask);
DLLAPI int STDCALL modbus_write_and_read_registers(modbus_t *ctx, int write_addr, int write_nb,
	const uint16_t *src, int read_addr, int read_nb, uint16_t *dest);
DLLAPI int STDCALL modbus_report_slave_id(modbus_t *ctx, int max_dest, uint8_t *dest);

DLLAPI modbus_mapping_t* STDCALL modbus_mapping_new_start_address(
	unsigned int start_bits, unsigned int nb_bits,
	unsigned int start_input_bits, unsigned int nb_input_bits,
	unsigned int start_registers, unsigned int nb_registers,
	unsigned int start_input_registers, unsigned int nb_input_registers);

DLLAPI modbus_mapping_t* STDCALL modbus_mapping_new(int nb_bits, int nb_input_bits,
	int nb_registers, int nb_input_registers);
DLLAPI void STDCALL modbus_mapping_free(modbus_mapping_t *mb_mapping);

DLLAPI int STDCALL modbus_send_raw_request(modbus_t *ctx, uint8_t *raw_req, int raw_req_length);

DLLAPI int STDCALL modbus_receive(modbus_t *ctx, uint8_t *req);

DLLAPI int STDCALL modbus_receive_confirmation(modbus_t *ctx, uint8_t *rsp);

DLLAPI int STDCALL modbus_reply(modbus_t *ctx, const uint8_t *req,
	int req_length, modbus_mapping_t *mb_mapping);
DLLAPI int STDCALL modbus_reply_exception(modbus_t *ctx, const uint8_t *req,
	unsigned int exception_code);

/**
* UTILS FUNCTIONS
**/

#define MODBUS_GET_HIGH_BYTE(data) (((data) >> 8) & 0xFF)
#define MODBUS_GET_LOW_BYTE(data) ((data) & 0xFF)
#define MODBUS_GET_INT64_FROM_INT16(tab_int16, index) \
    (((int64_t)tab_int16[(index)    ] << 48) + \
     ((int64_t)tab_int16[(index) + 1] << 32) + \
     ((int64_t)tab_int16[(index) + 2] << 16) + \
      (int64_t)tab_int16[(index) + 3])
#define MODBUS_GET_INT32_FROM_INT16(tab_int16, index) ((tab_int16[(index)] << 16) + tab_int16[(index) + 1])
#define MODBUS_GET_INT16_FROM_INT8(tab_int8, index) ((tab_int8[(index)] << 8) + tab_int8[(index) + 1])
#define MODBUS_SET_INT16_TO_INT8(tab_int8, index, value) \
    do { \
        tab_int8[(index)] = (value) >> 8;  \
        tab_int8[(index) + 1] = (value) & 0xFF; \
			    } while (0)
#define MODBUS_SET_INT32_TO_INT16(tab_int16, index, value) \
    do { \
        tab_int16[(index)    ] = (value) >> 16; \
        tab_int16[(index) + 1] = (value); \
			    } while (0)
#define MODBUS_SET_INT64_TO_INT16(tab_int16, index, value) \
    do { \
        tab_int16[(index)    ] = (value) >> 48; \
        tab_int16[(index) + 1] = (value) >> 32; \
        tab_int16[(index) + 2] = (value) >> 16; \
        tab_int16[(index) + 3] = (value); \
			    } while (0)

DLLAPI void STDCALL modbus_set_bits_from_byte(uint8_t *dest, int idx, const uint8_t value);
DLLAPI void STDCALL modbus_set_bits_from_bytes(uint8_t *dest, int idx, unsigned int nb_bits, const uint8_t *tab_byte);
DLLAPI uint8_t STDCALL modbus_get_byte_from_bits(const uint8_t *src, int idx, unsigned int nb_bits);
DLLAPI float STDCALL modbus_get_float(const uint16_t *src);
DLLAPI float STDCALL modbus_get_float_abcd(const uint16_t *src);
DLLAPI float STDCALL modbus_get_float_dcba(const uint16_t *src);
DLLAPI float STDCALL modbus_get_float_badc(const uint16_t *src);
DLLAPI float STDCALL modbus_get_float_cdab(const uint16_t *src);

DLLAPI void STDCALL modbus_set_float(float f, uint16_t *dest);
DLLAPI void STDCALL modbus_set_float_abcd(float f, uint16_t *dest);
DLLAPI void STDCALL modbus_set_float_dcba(float f, uint16_t *dest);
DLLAPI void STDCALL modbus_set_float_badc(float f, uint16_t *dest);
DLLAPI void STDCALL modbus_set_float_cdab(float f, uint16_t *dest);

#include "LibModbus/LibModbus-RTU.h"
#include "LibModbus/LibModbus-TCP.h"

#ifdef UPPROCESS
#ifndef LIBMODBUS_IMPLEMENT
#pragma comment(lib, "LibModbus.lib")
#endif
#endif

#endif  /* LIBMODBUS_H */