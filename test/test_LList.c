#include"DataStructure/LList.h"

int main(){
    LList llist = create();
    for(int i = 0; i < 10; i++){
        append(&llist, i);
    }
    traverse(llist);
    printf("\n");
    delete(&llist);
    moveToPos(&llist, 4);
    printf("%d ", getValue(llist));
    return 0;
}