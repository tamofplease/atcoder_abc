#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(M);
    vector<vector<int>> pos(N);
    rep(i, M)
    {
        int k;
        cin >> k;
        a[i] = vector<int>(k);
        rep(j, k) cin >> a[i][j];
        rep(j, k)
        {
            a[i][j]--;
            pos[a[i][j]].push_back(i);
        }
    }
    queue<int> q;
    vector<int> v(N);
    rep(i, M)
    {
        int p = a[i].back();
        v[p]++;
    }

    rep(i, N)
    {
        if (v[i] == 2)
        {
            q.push(i);
        }
    }

    int cnt = 0;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        cnt++;
        rep(i, 2)
        {
            int p = pos[t][i];
            a[p].pop_back();
            if (a[p].size())
            {
                int b = a[p].back();
                v[b]++;
                if (v[b] == 2)
                {
                    q.push(b);
                }
            }
        }
    }
    if (cnt == N)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
