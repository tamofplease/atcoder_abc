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
#define MAXM 18
#define MAXR 325
map<pair<int,int>,int> data;
int x[MAXR],y[MAXR],z[MAXR];
int tmp[MAXR],tmpb[MAXR];

bool sor(const int &a,const int &b){
    return a>b;
}

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
        ll ans2 = 0;
        if(count==P){
            int num[MAXM];
            memset(num,0,sizeof(num));
            for(int k=1;k<=M;k++){
                for(int j=0;j<P;j++){
                    pair<int,int> p = make_pair(tmp[j],k);
                    num[k-1] += data[p];
                }
            }
            sort(num,num+M,sor);
            for(int k=0;k<Q;k++){
                ans2 += num[k];
            }
        }
        ans = max(ans2,ans);
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d%d%d%d%d",&N,&M,&P,&Q,&R);
    for(int i=1;i<=R;i++){
        scanf("%d%d%d",&x[i],&y[i],&z[i]);
    }
    for(int i=0;i<=R;i++){
        for(int j=0;j<=R;j++){
            pair<int,int> p = make_pair(i,j);
            data[p] = 0;
        }
    }

    for(int i=1;i<=R;i++){
        pair<int,int> p = make_pair(x[i],y[i]);
        data[p] = z[i];
    }
    solve();
    
    return 0;
}