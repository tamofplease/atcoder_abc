#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++);

int main(){
    int D,G;
    cin >> D >> G;
    int p[11],c[11];
    
    int i,j;
    for(i=0;i<D;i++){
        cin >> p[i] >> c[i];
    }
    ll ans = 1000000;
    int count = 0;
    for(i=0;i<(1<<D);i++){
        count = 0;
        int tmp = 0;
        for(j = 0;j<D;j++){
            if(i&(1<<j)){
                tmp += (j+1)*100*p[j] + c[j];
                count += p[j];
                
            }
        }
        if(ans>=count&&tmp>=G){
            ans = count;
            //cout << ans << endl;
        }else if(tmp<G){
            for(j=D-1;j>=0;j--){
                if(i&(1<<j)){
                    continue;
                }else{
                    int ch = 0;
                    while(tmp<G && p[j]>ch){
                    tmp+=(j+1)*100;
                    count ++;
                    ch++;
                    //cout << tmp <<", " << count<< endl;
                    }
                }
                if(ans>=count&&tmp>=G){
                    ans = count;
                }
            }
        }
    }
    cout << ans<<endl;
    return 0;
}