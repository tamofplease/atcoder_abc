#include <iostream>
#include <vector>
using namespace std;
int N,K;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define MAXN 100001
typedef long long ll;
int A[MAXN];
int B[MAXN];
int color[MAXN];
bool col[MAXN];
int ran[MAXN];
ll ans = 0;

int main(){
    cin >> N >> K;
    vector<vector<int> > V(N);
    rep(i,N){
        col[i] = false;
        color[i] =1;
    }
    rep(i,N-1){
        cin >>A[i] >> B[i];
        A[i]--;B[i]--;
        V[A[i]].push_back(B[i]);
        V[B[i]].push_back(A[i]);
    }
    int top = 0;
    rep(i,N){
        if(V[i].size()>top){
            top = i;
        }
    }
    ran[top] = 1;color[top] = K;
    int tmp = K;
    rep(i,V[top].size()){
        color[V[top][i]] = tmp--;
    }
    
    

    return 0;
}