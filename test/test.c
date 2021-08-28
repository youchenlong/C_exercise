#include<stdio.h>
#include<stdint.h>

int main(){
    short v = -12345;
    unsigned short uv = (unsigned short)v;
    printf("v = %d, uv = %u\n", v, uv);

    // unsigned int u = 4294967295u;
    // int tu = (int)u;
    // printf("u = %u, tu = %d\n", u, tu);
    return 0;
}