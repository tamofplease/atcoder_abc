#include <iostream>

using namespace std;

typedef long long ll;

ll N;
#define MAXN 1000001
ll a[MAXN];
ll dp[MAXN];

int main(){
    cin >> N;
    for(int i=0;i<N;i++)cin >> a[i];
    dp[0] = 0;
    dp[1] = abs(a[0] - a[1]);
    for(int i=2;i<N;i++){
        dp[i] = min(dp[i-1] + abs(a[i-1] - a[i]) , dp[i-2] + abs(a[i-2] - a[i]));
    }
    cout << dp[N-1] << endl;
    return 0;
}