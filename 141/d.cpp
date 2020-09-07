#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll N,M;
#define MAXN 100001
#define MAXM 100001
ll A[MAXN];
int main(){
    cin >> N >> M;
    ll ans = 0;
    priority_queue<int> PQ;
    rep(i,N){
        cin >> A[i];
        PQ.push(A[i]);
    }
    rep(i,M){
        ll S = PQ.top();
        PQ.pop();
        PQ.push(S/2);
    }
    rep(i,N){
        ans += PQ.top();
       PQ.pop();
    }
    cout << ans << endl;
    return 0;

}