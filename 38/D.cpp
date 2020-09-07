#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef pair<int,int> P;
vector<P> V;
int N;
const int INF = 100000000;
int dp[100001];
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int W,H;
        cin >> W >> H;
        V.push_back(P(W,H));
    }
    sort(V.begin(),V.end());
    
    fill(dp,dp+N,INF);
    dp[0] = 0;
    int ans = 0;
    for(int i=0;i<N;i++){
        *upper_bound(dp,dp+N,V[i].second) = V[i].second;
    }
    int max =0 ;
    for(int i=0;i<N;i++){
        if(dp[i]!=INF)max = i;
    }
    cout << max << endl;
    return 0;
}