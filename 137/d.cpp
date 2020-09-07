#include <iostream>
#include <string>
#include <vector>


const int MAX_N = 110;
const int MAX_V = 100100;
long long max(long long a,long long b){
    if(a>b)return a;
    return b;
}
using namespace std;
typedef long long ll;

int main(){
    int N,M;
    cin >> N >> M;
    int A[10010];
    int B[10010];
    int i,j;
    for(i=0;i<N;i++){
        cin >> A[i] >> B[i];
    }
    long long dp[100][100];
    for(i=0;i<N;i++){
        for(j=0;j<100;j++){
            dp[i][j] = 0;
        }
    }
    for(i=0;i<M;i++){
    dp[0][i+A[0]] += 4;
    }
    for(i=0;i<M;i++){
        dp[1][i] = max(dp[0][i],dp[1][i]);
        if(M-i>=A[1])dp[1][i] = max(dp[0][i-1]+A[1],dp[1][i]);
    }


    
    return 0;
}