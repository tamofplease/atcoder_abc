#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define MAXQ 100001
#define MAXN 100001

ll N,K,Q;
ll A[MAXQ];
int d[MAXN];
int main(){
    cin >> N >> K >> Q;
    rep(i,Q){
        cin >> A[i];
        A[i]--;
    }
    rep(i,N)d[i] = K-Q;
    rep(i,Q){
        d[A[i]]++;
    }
    rep(i,N){
        if(d[i]<=0)cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;

}