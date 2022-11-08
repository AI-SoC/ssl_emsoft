#include <stdio.h>

typedef struct { 
    unsigned char b0 : 1;  
    unsigned char b1 : 1;  
    unsigned char b2 : 1;  
    unsigned char b3 : 1;  
    unsigned char b4 : 1;  
    unsigned char b5 : 1;  
    unsigned char b6 : 1;  
    unsigned char b7 : 1;  
} bits8;

typedef struct {
    unsigned char clk_mode : 4;
    unsigned char buf_mode : 2;
    unsigned char rst_mode : 2;
    unsigned char data_addr : 8; 
} ADC_MODE;

typedef union {
    unsigned short mode_2bytes;
    ADC_MODE      mode_bits; 
} SSL_ADC_MODE;

typedef struct { 
    unsigned char CNFG1;  
    unsigned char CNFG2;  
    //unsigned short MODE;
    SSL_ADC_MODE    MODE;
    unsigned char BUF[2];
} ADC_CONFIG;

typedef union {
    ADC_CONFIG      adc;
    unsigned char   bytes[4];
    bits8           regs[4];
} SSL_ADC;

#define ADC_EN_BIT 0
#define ADC_AUTO_BIT 7
#define CLK_DIV_2 0x01
#define CLK_DIV_4 0x02
#define CLK_DIV_8 0x04
#define CLK_DIV_16 0x08

int main() {
    printf("Running...\n")  ;

    ADC_CONFIG adc1 = {0x01, 0x80, 0xF000, 0x11, 0x11};

    printf("ADC is 0x%8X at %p\n", adc1, &adc1);
    printf("ADC.CNFG1 is 0x%2X at %p\n", adc1.CNFG1, &adc1.CNFG1);
    printf("ADC.CNFG2 is 0x%2X at %p\n", adc1.CNFG2, &adc1.CNFG2);
    printf("ADC.MODE is 0x%4X at %p\n", adc1.MODE.mode_2bytes, &adc1.MODE.mode_2bytes);
    printf("ADC.BUF is 0x%X at %p\n", adc1.BUF[0], adc1.BUF);

    unsigned char* adc_p = (unsigned char*)&adc1;

    printf("\nADC_p is 0x%2X at %p\n", *(adc_p+0), adc_p);
    printf("ADC.CNFG2 is 0x%2X at %p\n", *(adc_p+1), &adc1.CNFG2);
    printf("ADC.MODE is 0x%4X at %p\n", *(unsigned short *)(adc_p+2), &adc1.MODE);
    //printf("ADC.BUF is 0x%X at %p\n", adc1.BUF, &adc1.BUF);

    printf("\n");
    if(adc1.CNFG1 & (1<<ADC_EN_BIT))   printf("ADC is enabled!!!\n") ;
    if(adc1.CNFG2 & (1<<ADC_AUTO_BIT))   printf("Auto mode enabled!!!\n") ;

    SSL_ADC s_adc = {0x01, 0x80, 0xF091};
    if(s_adc.regs[0].b0)  printf("ADC is enabled!!!\n") ;
    
    if(s_adc.adc.MODE.mode_bits.clk_mode == CLK_DIV_2)
        printf("ADC clock source is divided by 2 from sys clock\n");

    return 0;
}
