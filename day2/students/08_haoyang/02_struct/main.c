#include <stdio.h>


typedef struct 
{
    /* data */
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
} bits8; /* No Struct Name */


typedef struct 
{
    /* data */
    unsigned char clk_mode : 4;
    unsigned char buf_mode : 2;
    unsigned char rst_mode : 2;
    unsigned char data_addr : 8;
}ADC_MODE;

typedef union 
{
    /* data */
    unsigned short mode_2bytes;
    ADC_MODE mode_bits;
}SSL_ADC_MODE;



typedef struct 
{
    /* data */
    unsigned char CNFG1;
    unsigned char CNFG2;
    //unsigned short MODE;
    SSL_ADC_MODE  MODE;
    unsigned char BUF[8];
} ADC_CONFIG;

typedef union
{
    /* data */
    ADC_CONFIG adc;
    unsigned bytes[4];
    bits8    regs[4];
} SSL_ADC;



#define ADC_EN_BIT 0
#define ADC_AUTO_BIT 7

#define CLK_DIV_2 0x01
#define CLK_DIV_4 0x02
#define CLK_DIV_8 0x04
#define CLK_DIV_16 0x08

int main() {
    printf("Running...\n");

    ADC_CONFIG adc1 = {0x01,0x80,0xF000};

    printf("ADC.CONFIG1 is 0x%2X\n",adc1.CNFG1);    
    printf("ADC.CONFIG2 is 0x%2X\n",adc1.CNFG2);    
    printf("ADC.MODE is 0x%4X\n",adc1.MODE.mode_2bytes);    

    unsigned char* adc_p = (unsigned char*) & adc1;

    printf("ADC.CONFIG1 is 0x%2X\n",*(adc_p+0));    
    printf("ADC.CONFIG2 is 0x%2X\n",*(adc_p+1));    
    //Address Translation is Needed
    printf("ADC.MODE is 0x%4X\n",*(unsigned short*) (adc_p+2));   

    if (adc1.CNFG1 & (1<<ADC_EN_BIT))
        printf("ADC is enabled\n"); 

    if (adc1.CNFG2 & (1<<ADC_AUTO_BIT))
        printf("Auto Start mode is enabled\n");

    SSL_ADC s_adc = {0x01,0x80,0xF091};
    
    if (s_adc.regs[0].b0)
        printf("ADC is enabled\n");

    if (s_adc.adc.MODE.mode_bits.clk_mode == CLK_DIV_2)
        printf("ADC clk source is divided by 2 from sys clk\n");

    return 0;
}