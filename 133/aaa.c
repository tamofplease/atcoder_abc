#include <stdio.h>

int main(){
    int A[100000];
    int N;

    scanf("%d",&N);
    int i;
    int max = 1;

    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
        if(max<A[i])max = A[i];
    }
    
    int ANS[100000];
    int x;
    for(i=0;i<N;i++){
        for(x=0;x<max;x++){
            ANS[i] = 2*x;
            Ans[i+1] = (A[i+1]-x)*2;
            ANS[i+2] = (A[i+2])
            A[i]-x
        }
    }
    return 0;
}