#include<stdio.h>
#include"Caesar.h"

int main(){
    char plaintxt[100] = "meet me after the toga party";
    char ciphertxt[100];
    Caesar(plaintxt, ciphertxt, 100);
    fputs(ciphertxt, stdout);
    return 0;
}