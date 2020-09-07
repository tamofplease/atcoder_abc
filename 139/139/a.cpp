#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string S,T;
    cin >> S;
    cin >> T;
    int ans = 0;
    for(int i=0;i<3;i++){
        if(S[i] == T[i])ans++;
    }
    
    cout << ans << endl;
    return 0;

}