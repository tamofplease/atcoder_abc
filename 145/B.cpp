#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N;
    string S;
    cin >> N >> S;
    bool ok = true;
    for(int i=0;i<(N/2);i++){
        if(S[i]!=S[i+(N/2)]){
            ok = false;
        }
    }
    if(ok&&N%2==0)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}