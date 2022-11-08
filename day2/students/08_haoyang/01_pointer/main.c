#include <stdio.h>

int main() {
    printf("Running...\n");

    int a = 0x12345678;
    
    int* ap = &a;
    printf("a is %X at %p\n",a,ap);
    char* abp = (char*) & a;

    printf("a is 0x%x at 0x%p\n", *abp, abp);

    //TO replace the 34 in a with 5A
    *(abp + 2) = 0x5A;
    printf("a is %X at %p\n",a,ap);
    
    return 0;
}
