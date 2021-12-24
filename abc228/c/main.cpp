#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n, k; cin >> n >> k;
    vector<int> scores(n, 0);
    rep(i, n) {
        int a,b,c;cin >> a >> b >> c;
        scores[i] = a+b+c;
    }

    vector<int> sorted_scores(n);
    sorted_scores = scores;
    sort(sorted_scores.begin(), sorted_scores.end(), greater<int>());
    int current_k_score = sorted_scores[k-1];

    rep(i,n) {
        if(current_k_score <= scores[i] + 300) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
