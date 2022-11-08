#include <stdio.h>

typedef struct { //12 byte struct
    unsigned char CNFG1;  
    unsigned char CNFG2;  
    unsigned short MODE;
    unsigned char BUF[2];
} ADC_CONFIG;

int main() {
    printf("Running...\n")  ;

    ADC_CONFIG adc1 = {0x01, 0x80, 0xF000, 0x11, 0x11};

    printf("ADC is 0x%8X at %p\n", adc1, &adc1);
    printf("ADC.CNFG1 is 0x%2X at %p\n", adc1.CNFG1, &adc1.CNFG1);
    printf("ADC.CNFG2 is 0x%2X at %p\n", adc1.CNFG2, &adc1.CNFG2);
    printf("ADC.MODE is 0x%4X at %p\n", adc1.MODE, &adc1.MODE);
    printf("ADC.BUF is 0x%X at %p\n", adc1.BUF[0], adc1.BUF);

    unsigned char* adc_p = (unsigned char*)&adc1;

    printf("\nADC_p is 0x%2X at %p\n", *(adc_p+0), adc_p);
    printf("ADC.CNFG2 is 0x%2X at %p\n", *(adc_p+1), &adc1.CNFG2);
    printf("ADC.MODE is 0x%4X at %p\n", *(unsigned short *)(adc_p+2), &adc1.MODE);
    //printf("ADC.BUF is 0x%X at %p\n", adc1.BUF, &adc1.BUF);

    return 0;
}
