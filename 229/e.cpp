#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int N,M;

struct UnionFind
{
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N)
    { //最初は全てが根であるとして初期化
        for (int i = 0; i < N; i++)
            par[i] = i;
    }

    int root(int x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {                     // xとyの木を併合
        int rx = root(x); // xの根をrx
        int ry = root(y); // yの根をry
        if (rx == ry)
            return;   // xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool same(int x, int y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};


int A[220000],B[220000];
void input() {
    cin >> N >> M;
    rep(i, M) {
        cin >> A[i] >> B[i];
    }
}

int ans[2200000];
UnionFind tree(220000);
void solve() {
    rep(i, M) {
       int j = M - i - 1; 
       int a = A[j], b = B[j];
       
       tree.unite(a, b);
       ans[j] = 
    }
}

int main(){
    input();
    solve();
    return 0;
}
