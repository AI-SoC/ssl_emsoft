#include <stdio.h>

//#define HW_REG 1

#ifdef HW_REG
    #define ADC_DATA *((volatile unsigned char*)0xBC000000)
#endif

int main() {
    printf("Running...\n");

#ifndef HW_REG
    volatile int ADC_DATA = 8;
#else
    ADC_DATA = 8;
#endif

    int b;
    b = ADC_DATA + 2;

    printf("b is %d\n", b);

    return 0;
}
