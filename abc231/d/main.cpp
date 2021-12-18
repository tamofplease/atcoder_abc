#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

class UnionFind
{
public:
    // 親の番号を格納する。親だった場合は-(その集合のサイズ)
    vector<int> Parent;

    UnionFind(int N)
    {
        Parent = vector<int>(N, -1);
    }

    // Aがどのグループに属しているか調べる
    int root(int A)
    {
        if (Parent[A] < 0)
            return A;
        return Parent[A] = root(Parent[A]);
    }

    // 自分のいるグループの頂点数を調べる
    int size(int A)
    {
        return -Parent[root(A)]; //親をとってきたい]
    }

    // AとBをくっ付ける
    bool connect(int A, int B)
    {
        // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if (A == B)
        {
            //すでにくっついてるからくっ付けない
            return false;
        }

        // 大きい方(A)に小さいほう(B)をくっ付ける
        // 大小が逆だったらひっくり返す
        if (size(A) < size(B))
        {
            swap(A, B);
        }

        // Aのサイズを更新する
        Parent[A] += Parent[B];
        // Bの親をAに変更する
        Parent[B] = A;

        return true;
    }
};

int main(){
    int N, M; cin >> N >> M;
    UnionFind uni(N);
    vector<int> A(M), B(M);
    vector<vector<int>> G(N);
    rep(i, M) {
        cin >> A[i] >> B[i];
        G[A[i]-1].push_back(B[i]-1);
        G[B[i]-1].push_back(A[i]-1);
    }
    
    rep(i, N) {
        if(G[i].size() > 2) {
            cout << "No" << endl;
            return 0;
        }
    }

    rep(i, M)
    {
        int a, b;
        a = A[i] - 1;
        b = B[i] - 1;
        if (uni.root(a) == uni.root(b))
        {
            cout << "No" << endl;
            return 0;
        }        
        uni.connect(a, b);
    }
    cout << "Yes" << endl;
    return 0;
}
