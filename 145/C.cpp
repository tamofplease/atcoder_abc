#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define MAXN 8
int main(){
    int N;
    cin >> N;
    int x[MAXN],y[MAXN];
    rep(i,N)cin >> x[i] >> y[i];
    double dist = 0;
    int count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j)continue;
            else{
                double dts = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                dist += sqrt(dts);
                count++;
            }
        }
    }
    dist /= N;
    printf("%0.8f\n",(dist));
    return 0;
}