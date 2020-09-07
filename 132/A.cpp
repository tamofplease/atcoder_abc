#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string S;
    cin >> S;
    map<char,int> M;
    rep(i,4){
        if(M.find(S[i])==M.end()){
            M[S[i]] = 1;
        }else{
            M[S[i]]++;
        }
    }
    rep(i,4){
        if(M[S[i]]==2)continue;
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}