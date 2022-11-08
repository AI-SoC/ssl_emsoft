#include <stdio.h>

int main() {
    printf("Running...\n")  ; 

    int a = 0x12345678      ;

    int* ap = &a ; 
    printf("a is 0x%8X at %p\n", *ap, ap);

    char* abp = (char*)&a   ; 

    printf("a is 0x%X at %p\n", *abp, abp);

    *(abp + 2)  = 0x5A ; 
    printf("a is 0x%8X at %p\n", *ap, ap);

    return 0;
}
