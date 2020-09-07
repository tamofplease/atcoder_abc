#include <stdio.h>

int main(){
    int N ;
    int H[100010];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&H[i]);
    }
    int i,j;
    int flag = 0;
    for(i=0;i<N-1;i++){
        if(H[i]>H[i+1]){
            H[i] = H[i]-1;
        }
    }
    
    for(i=0;i<N-1;i++){
        if(H[i]>H[i+1]){
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Yes\n");
    }else printf("No\n");
    return 0;
}