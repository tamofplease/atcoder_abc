#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int checker = 0;
    scanf("%d",&N);
    int *a;

    a = malloc(sizeof(int)*(N+1));
    int data[200001]
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
        
    }
    for(int i=0;i<N;i++){
        if(a[i]==1){
            for(int j=0;j<i;j++){
                if(i%j==0){
                    d
                }
            }
        }
    }
    int count=0;
    for(int i=0;i<N;i++){
        if(a[i]>N/(1+i))checker = 1;
        if(a[i]%2!=0){
            count++;
        }
        
    }
    if(checker==1){
        printf("-1\n");
    }else{
    printf("%d\n",count);
    for(int i=0;i<N;i++){
        if(a[i]%2!=0){
            printf("%d ",i+1);
        
        }
        
    }
    }
    return 0;
}
