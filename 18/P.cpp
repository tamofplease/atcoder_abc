#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <tgmath.h>
#include <cstring>
#define MOD 1000000007
using namespace std;
#define INT_MAX 2147000000
#define LONG_MAX 9223372036854775806

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int N,M,P,Q,R;
#define MAXR 325
map<pair<int,int>,int> data;
int x[MAXR],y[MAXR],z[MAXR];
int tmp[MAXR],tmpb[MAXR];
void solve(){
    ll ans = 0;
    for(int i=0;i<(1<<N);i++){
        
        int count = 0;
        memset(tmp,0,sizeof(tmp));
        for(int j=0;j<N;j++){
            if((i>>j)&1==1){
                tmp[count] = j+1;
                count++;
            }
        }

        if(count==P){
            //rep(k,count)cout << tmp[count] <<  " ";
            //cout << endl;
            for(int j=0;j<(1<<M);j++){
                int countb = 0;
                memset(tmpb,0,sizeof(tmpb));
                for(int k=0;k<M;k++){
                    if((j>>k)&1==1){
                        tmpb[countb] = k+1;
                        countb++;
                    }
                }
                if(countb==Q){
                    ll ans2 = 0;
                    rep(j,Q){
                        rep(k,P){
                            pair<int,int> p = make_pair(tmp[k],tmpb[j]);
                            ans2 += data[p];
                        }
                    }
                    ans = max(ans2,ans);
                }
            }
            
        }
        
    }
    printf("%d\n",ans);
}

int main(){
    //scanf("%d%d%d%d%d",&N,&M,&P,&Q,&R);
    N = 18;
    M = 18;
    P = 18;
    Q = 18;
    R = N*M;
    int j = 1;
    for(int i=0;i<=R;i++){
        for(int j=0;j<=R;j++){
            pair<int,int> p = make_pair(i,j);
            data[p] = 0;
        }
    }
    for(int i=1;i<=18;i++){
        for(j=1;j<=18;j++){
            pair<int,int> p = make_pair(i,j);
            data[p] = 10000;
        }
    }
    solve();
    
    return 0;
}