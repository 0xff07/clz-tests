#include "clz_Generic.h"
#include <stdio.h>
#include <stdint.h>
static const int magic[]={2,1,0,0};

//static inline __attribute((always_inline))
unsigned clz32(uint32_t x)
{
    uint16_t upper = (uint16_t)(x >> 16);
    uint16_t lower = (uint16_t)(x & 0xFFFF);
    return upper ? clz(upper) : 16 + clz(lower);
}

unsigned clz16(uint16_t x)
{
    uint8_t upper = (uint8_t)(x >> 8);
    uint8_t lower = (uint8_t)(x & 0xFF);
    return upper ? clz(upper) : 8 + clz(lower);
}

unsigned clz8(uint8_t x)
{
    if (x == 0) return 8;
    int n = 0;
    if (x <= 0x0F) { n += 4; x <<= 4; }
    if (x <= 0x3F) { n += 2; x <<= 2; }
    if (x <= 0x7F) { n += 1; x <<= 1; }
    return n;


}
