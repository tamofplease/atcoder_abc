#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define MAXN 21
int main(){
    int n;
    int p[MAXN];
    cin >> n;
    rep(i,n)cin >> p[i];
    int count = 0;
    for(int i=1;i<n-1;i++){
        if(p[i-1]<p[i]&&p[i]<p[i+1])count++;
        else if(p[i-1]>p[i]&&p[i]>p[i+1])count++;
    }
    cout << count << endl;
    return 0;
}