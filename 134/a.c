#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    int checker = 0;
    scanf("%d",&N);
    int *a;
    int i,j;
    int *b;
    int all = 0;
    b = malloc(sizeof(int)*(N+1));
    a = malloc(sizeof(int)*(N+1));
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
        if(a[i]==1){
            all++;
            for(j=1;j<i;j+=j){
                if((i)%(j)==0){
                    a[j-1]++;
                    all++;
                }
            }
        }
    }
    if(all>N)checker = 1;
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
        if(a[i]%2==b[i]){
            continue;
        }else{
            printf("%d ",i+1);
        }
        
    }
    }
    return 0;
}
