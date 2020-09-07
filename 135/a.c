#include <stdio.h>
#include <stdlib.h>
int main(){
    int A,B;
    int K;
    scanf("%d%d",&A,&B);
    
        K = (A+B)/2;
    if(2*K !=A+B){
    printf("IMPOSSIBLE\n");
    }else
    printf("%d\n",K);
    return 0;
}