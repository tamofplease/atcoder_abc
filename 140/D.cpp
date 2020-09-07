#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N,K;
    string S;
    cin >>N >> K >> S;
    string T;
    int b=0,f=0;
    int ans =0;
    for(int i=0;i<N-1;i++){
        if(S[i]=='L' && S[i+1]=='R')b++;
        if(S[i]=='R' && S[i+1]=='L')f++;
        if(S[i] == S[i+1])ans++;
    }
    int true_ans = 0;
    int mini = min(b,min(f,K));
    ans += 2*min(b,min(f,K));
    if(mini == K){
        true_ans = ans;
    }else {
        if(K-min(f,b) >= 2)true_ans = ans + 2;
        else true_ans = ans + 1;
    }

    cout << min (max(N-1, 0)  ,true_ans) << endl;;

    return 0;

}