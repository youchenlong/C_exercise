#include"DataStructure/AStack.h"

int main(){
    AStack s;
    create(&s, 10);
    for(int i = 0; i < 10; i++){
        push(&s, i);
    }
    while(s.sp != s.size){
        printf("%d ", pop(&s));
    }
    return 0;
}