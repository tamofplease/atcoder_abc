#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

pair<int, int> battle(char a, char b) {
    if((a == 'G' && b == 'C') || (a == 'C' && b == 'P') || (a == 'P' && b == 'G')) 
        return make_pair(1, 0);
    if ((b == 'G' && a == 'C') || (b == 'C' && a == 'P') || (b == 'P' && a == 'G'))
        return make_pair(0, 1);
    return make_pair(0, 0);
}

int main(){
    int n, m; cin >> n >> m;
    vector<pair<int, int>> ps(2*n);//特典、番号
    rep(i, 2*n) {
        ps[i] = make_pair(0, i);
    }
    vector<string> a(n*2+1);
    rep(i, 2*n) {
        cin >> a[i];
    }

    rep(i, m) {
        for(int j = 0; j < 2*n ; j+=2) {
            int f_num = ps[j].second;
            int s_num = ps[j+1].second;
            pair<int, int> tm = battle(a[f_num][i], a[s_num][i]);
            ps[j] = make_pair(ps[j].first + tm.first, f_num);
            ps[j+1]  = make_pair(ps[j+1].first + tm.second, s_num);
        }
        sort(ALL(ps), [](pair<int, int> a, pair<int, int> b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });
    }

    rep(i, 2*n) {
        cout << ps[i].second + 1 << endl;
    }

    return 0;
}
