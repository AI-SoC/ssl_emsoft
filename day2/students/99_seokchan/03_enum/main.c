#include <stdio.h>

#define _EOC_IDX 3

typedef enum {
    EOC = 1<<_EOC_IDX,
    SOC = 1
} ADC_STATUS ; 

enum SSL_ACC_MODE {
    ACC_EN = (1<<7) ,   // 0b1xxx_xxxx
    ACC_ST = (1<<3)     // 0bxxxx_1xxx
};

ADC_STATUS get_adc_status() {
    /*if ( adc1.data & 0x08 )
        retrun 0x8; // end of conversion (EOC)
    else 
        return 0*/

    return EOC; 
}

int main() {
    printf("Running...\n")  ;

    if(get_adc_status() == EOC)
        printf("ADC conversion finished\n");

    while (get_adc_status() != EOC) ;  //blocking 

#ifdef HW_REG
    // #define ACC_MODE (*(unsigned char*)(0xB000_0000))
#else
    unsigned char ACC_MODE = 0; 
#endif 

    ACC_MODE = 0 ;
    ACC_MODE |= ACC_EN ; 
    ACC_MODE |= ACC_ST ; 

    return 0;
}
