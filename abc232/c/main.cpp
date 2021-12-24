#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

void print(const std::vector<int> &v)
{
    std::for_each(v.begin(), v.end(), [](int x)
                  { std::cout << x << " "; });
    std::cout << std::endl;
}

set<int> vtos(vector<int> v)
{
    // Declaring the  set
    set<int> s;

    // Traverse the Vector
    for (int x : v)
    {

        // Insert each element
        // into the Set
        s.insert(x);
    }

    // Return the resultant Set
    return s;
}

int main(){
    int n, m; cin >> n >> m;
    vector<int> v(n);
    vector<vector<int>> a(n), t(n);
    rep(i, m) {
        int x,y; cin >> x >> y;
        x--;y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        x--;y--;
        t[x].push_back(y);
        t[y].push_back(x);
    }
    rep(i, n) v[i] = i;
    do {
        bool flag = true;
        rep(i, n) {
            vector<int> updatedA(a[i].size());
            rep(j, a[i].size()) updatedA[j] = v[a[i][j]];
            set<int> as = vtos(updatedA);
            set<int> ts = vtos(t[v[i]]);
            if(as != ts) {
                flag = false;
            }
        }
        if(flag) {
            puts("Yes");
            return 0;
        }
    } while(next_permutation(v.begin(), v.end()));
    puts("No");
    return 0;
}
