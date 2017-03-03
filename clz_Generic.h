#ifndef CLZ_GENERIC_H
#define CLZ_GENERIC_H
#include <stdio.h>
#include <stdint.h>

#define clz(T) _Generic((T), \
    uint8_t : clz8,\
    uint16_t : clz16, \
    default : clz32 \
)(T)

unsigned clz32(uint32_t x);
unsigned clz16(uint16_t x);
unsigned clz8(uint8_t x);

#endif
