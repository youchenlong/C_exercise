#include"../DataStructure/LStack.h"

void print_binary(int decimal){
    LStack s = create();   
    int quotient = decimal / 2;
    int remainder = decimal % 2;
    while(1){
        push(&s, remainder);
        remainder = quotient % 2;
        quotient = quotient / 2;
        if(quotient == 0 && remainder == 0)break;  
    }
    while(s.count != 0){
        printf("%d", pop(&s));
    }
}