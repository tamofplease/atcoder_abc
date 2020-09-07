#include <stdio.h>

int main(){
    long int L,R;
    int i,j;
    int ans = 2020;
    scanf("%lu%lu",&L,&R);
    int defL = L;
    int defR = R;
    if(defR-defL >= 2019){
    }else{
    while(L>=2019 || R>=2019){
    L = L%2019;
    R = R%2019;
    }
    
    
    for(i=L;i<R;i++){
        for(j=i+1;j<=R;j++){
            int sub = i*j;
            while(sub>=2019){
                sub=sub%2019;
            }
            if(sub<ans){
                ans = sub;
            }
        }
    }
    }
    if( defR-defL >= 2019)ans = 0;
    printf("%d\n",ans);
    return 0;
}