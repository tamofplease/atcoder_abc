#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int main(){
    string s;cin >> s;
    int l = s.size();
    ll ans = 0;
    for(int i=0;i<(1<<(l-1));i++){
        ll tot = 0;
        for(int j=0;j<l;j++){
            tot *= 10;
            tot += s[j] -'0';
            if(!(i&(1<<j))){
                ans += tot;
                tot = 0;
            }
        }
        ans += tot;
    }
    cout << ans << endl;
    return 0;
}