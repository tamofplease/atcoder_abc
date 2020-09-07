#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int N,M;
#define MAXN 100001
int X[MAXN];
int main(){
    cin >> N >> M;
    rep(i,M){
        cin >> X[i];
        X[i]--;
    }
    int ans = 0;
    sort(X,X+M);
    int skip = N-1;
    priority_queue<int> V;
    if(N>=M)cout << ans << endl;
    else{
        rep(i,M-1){
            V.push(X[i+1]-X[i]);
        }
        ans = X[M-1]-X[0];
        rep(i,skip){
            ans -= V.top();
            V.pop();
        }
        cout << ans << endl;
    }
    
    return 0;
}