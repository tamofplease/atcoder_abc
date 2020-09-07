#include <iostream>

using namespace std;
#define rep(i,N) for(int i=0;i<N;i++)
int N,M;
string S;
#define MAXN 100001
int ans[MAXN];
int k;
void solve(){
    int count = 0;
    rep(i,N+1){
        if(S[i]=='1')count++;
        if(S[i]=='0')count = 0;
        if(count>=M){
            ans[0] = -1;
            k  = 1;
            return;
        }
    }
    k=0;
    for(int i=N;i>=0;i--){
        int start;
        if(i-M<0)start = 0;
        else start = i-M;
        for(int j=start;j<=i;j++){
            if(i==0&&j==0)return;
            if(S[j]=='0'){
                ans[k] = i-j;
                i -= (ans[k]-1);
                k++;
                j = i+1;
            }
            
        }
    }

}


int main(){
    cin >> N >> M;
    cin >> S;
    solve();
    for(int i=k-1;i>=0;i--){
        cout << ans[i] <<" ";
    }
    cout << endl;
    return 0;
}