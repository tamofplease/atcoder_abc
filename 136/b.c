#include <stdio.h>

int main(){
    int N;
    scanf("%d",&N);
    int count = 0;
    for(int i=1;i<=N;i++){
        if(i>=1&&i<10)count++;
        if(i>=100&&i<1000)count++;
        if(i>=10000 && i<100000)count++;
    }
    printf("%d",count);
    return 0;
}