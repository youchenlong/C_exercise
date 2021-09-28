#include<stdio.h>

int main(){
    int page = 0x1234abcd;          // 逻辑地址
    int p = page >> 16;             // 页码
    int d = page & 0x0000ffff;      // 偏移量
    int f = 0;                      // 帧码
    // 查页表
    if(p == 0x1234){
        f = 0x5678;
    }
    int frame = f << 16 | d; // 物理地址
    printf("%x\n", page);
    printf("%x\n", frame);
    return 0;
}