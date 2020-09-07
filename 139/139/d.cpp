#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++);
int main(){
    int N;
    cin >> N;
    ll ans = 0;
    for(int i=1;i<N;i++){
        ans += i;
    }
    cout << ans << endl;
    return 0;
}