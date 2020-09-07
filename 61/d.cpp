#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll N,M;
#define INF 2000000000100
#define MAXN 1001
#define MAXM 2001
ll d[MAXN];
ll a[MAXM],b[MAXM],c[MAXM];
int main(){
    cin >> N >> M;
    rep(i,N)d[i] = -INF;
    rep(i,M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--,b[i]--;
    }
    d[0] = 0;
    bool ch = true;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(d[b[j]]<d[a[j]]+c[j]){
                d[b[j]] = d[a[j]]+c[j];
                if(i==N-1&&b[j]==N-1)ch =false;
            }
        }
    }
    if(ch){
        cout << d[N-1] << endl;
    }else{
        cout << "inf" << endl;
    }
    
    return 0;

}