#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int cur = 0;
    stack<pair<int, int>> q;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (q.empty())
        {
            q.push({a, 1});
            cur++;
        }
        else
        {
            pair<int, int> p = q.top();
            if (p.first == a)
            { // 先頭と値が等しかった場合
                q.pop();
                if (p.second + 1 == p.first)
                { /// aと等しくなる場合
                    cur -= p.second;
                }
                else
                {
                    q.push({p.first, p.second + 1});
                    cur++;
                }
            }
            else
            {
                q.push({a, 1});
                cur++;
            }
        }
        cout << cur << endl;
    }
    return 0;
}
