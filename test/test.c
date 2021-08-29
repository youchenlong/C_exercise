#include<stdio.h>
#include<stdint.h>

int main(){
    if(-INT32_MAX-1 < INT32_MAX){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}