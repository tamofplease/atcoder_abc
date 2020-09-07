#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string S;
    cin >> S;
    bool ye = true;
    for(int i=0;i<S.length();i+=2){
        if(S[i]=='L')ye = false;
    }
    for(int i=1;i<S.length();i+=2){
        if(S[i]=='R')ye = false;
    }
    if(ye)cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;

}