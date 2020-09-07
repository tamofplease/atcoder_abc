#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin >> n;
    vector<int> V(n);
    rep(i,n)cin >> V[i];
    sort(V.begin(),V.end());
    cout << V[n/2]-V[(n/2)-1] << endl;
    return 0;
}