#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int N,T;
#define MAXN 3000

int dp[MAXN];

int main(){
    
    for(int i=0;i<N;i++){
        dp[0] = A[i];
        for(int j=0;j<N;j++){
            if(i==j)continue;
            dp[B[j]] = A[j];
        }
    }

    return 0;
}