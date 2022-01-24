#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int n;
#include <functional>

#include <iostream>

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f)
{
    if (rest == 0)
    {
        f(indexes);
    }
    else
    {
        if (s < 0)
            return;
        recursive_comb(indexes, s - 1, rest, f);
        indexes[rest - 1] = s;
        recursive_comb(indexes, s - 1, rest - 1, f);
    }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f)
{
    int indexes[k];
    recursive_comb(indexes, n - 1, k, f);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector<vector<int>> a(n*2, vector<int>(n*2));
    vector<int> tmp(n*2);
    rep(i, 2*n) tmp[i]=i;
    foreach_comb(n*2, n, [](int *indexes) { 
        
        rep(i, n) {
            cout << indexes[i] << " ";
        }
        cout << endl;
    });
    
    return 0;
}
