#include <stdio.h>
#include <assert.h>
#include "clz_Generic.h"

int main()
{
    uint32_t a = 1;
    a = clz(a);
    uint16_t b = 1;
    b = clz(b);
    uint8_t c = 1;
    c = clz(c);


    for (uint32_t i = 0; i < 31; i++) {
        printf("%u:%d \n",1<<i,clz((1<<i)));
        for (uint32_t j = (1 << i); j < (1 << (i + 1)); j++) {
            assert( __builtin_clz (j) == clz(j));
        }
    }

   for (uint16_t i = 0; i < 15; i++) {
        printf("%u:%d \n",1<<i,clz((1<<i)));
        for (uint16_t j = (1 << i); j < (1 << (i + 1)); j++) {
            assert( (__builtin_clz (j) - 16) == clz(j));
        }
    }
   for (uint8_t i = 0; i < 7; i++) {
        printf("%u:%d \n",1<<i,clz((1<<i)));
        for (uint8_t j = (1 << i); j < (1 << (i + 1)); j++) {
            assert( (__builtin_clz (j)-24) == clz(j));
        }
    }


    return 0;
}
