#include <stdio.h>

void Loop(int *number);

int main(){
    int n;

    printf("Type number you want: ");
    scanf("%d",&n);

    Loop(&n);
    return 0;
}

void Loop(int *number){
    
    for(int i = 0 ; i < *number ; i++){
        printf("[%d] Hello world\n",i);
    }
    
}