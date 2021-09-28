#include<malloc.h>

void Caesar(char *plaintxt, char *ciphertxt, int length){
    int i = 0;
    while(i < length){
        // 小写字母
        if(plaintxt[i] >= 0x61 && plaintxt[i] <= 0x61+26){
            ciphertxt[i] = (plaintxt[i] - 0x61 + 3) % 26 + 0x41;
        }
        // 大写字母
        else if(plaintxt[i] >= 0x41 && plaintxt[i] <= 0x41+26){
            ciphertxt[i] = (plaintxt[i] - 0x41 + 3) % 26 + 0x41;
        }
        // 其他字符
        else{
            ciphertxt[i] = plaintxt[i];
        }
        i++;
    }
}