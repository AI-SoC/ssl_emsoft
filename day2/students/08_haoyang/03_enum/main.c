# include <stdio.h>

#define _EDC_IDX 3


typedef enum {
    EDC = 1 << _EDC_IDX,
    SOC = 1
}ADC_STATUS;


ADC_STATUS get_adc_status(){

    return EDC;
}

enum SSL_ACC_MODE {
    ACC_EN = (1<<7),
    ADC_ST = (1<<3)
};


void main(){
    printf("Running...\n");

    if (get_adc_status()==EDC)
        printf("ADC Conversion finished\n");

    while (get_adc_status() != EDC); //blocking

    return 0;
}