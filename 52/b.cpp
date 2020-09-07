#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define MOD 1000000007
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    int num = 0;
    rep(i,N){
        if(S[i]=='I'){
            num += 1;
            ans = max(ans,num);
        }else if(S[i]=='D'){
            num -=1;
        }
    }
    cout << ans << endl;
    return 0;
}