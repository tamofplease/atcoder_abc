#include <stdio.h>

int main(){
    int N ;
    scanf("%d",&N);
    int A[200000];
    int B[200002];
    int i;
    for(i=0;i<N+1;i++){
        scanf("%d",&A[i]);
    }
    for(int j=0;j<N;j++){
    scanf("%d",&B[j]);
    }
    long all=0;
    for(i=0;i<N;i++){
        if(B[i]>=A[i]&&A[i]>=0&&B[i]>=0){
            B[i]=B[i]-A[i];
            all+=A[i];
            A[i] = 0;
        }else if(B[i]>=0&&A[i]>=B[i]&&A[i]>=0){
            all+=B[i];
            A[i]=A[i]-B[i];
            B[i] = 0;
        }
        if(B[i]>0&&A[i+1]>0){
            if(A[i+1]>=B[i]){
                A[i+1]=A[i+1]-B[i];
                all+=B[i];
                B[i] = 0;
            }else if(B[i]>=A[i+1]){
                all+=A[i+1];
                A[i+1] = 0;
                B[i] = 0;
            }
        }
    }
    
    printf("%ld\n",all);
    
    return 0;
}