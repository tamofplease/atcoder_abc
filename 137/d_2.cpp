#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int N,M;
#define MAXN 100001
typedef pair<int,int> P;
bool used[MAXN];
typedef long long ll;
bool sor(P &a,P &b){
    if(a.second==b.second)return a.first < b.first;
    return a.second<b.second;
}
int main(){
    fill(used,used+N,false);
    cin >> N >> M;
    vector<P> V(N);
    rep(i,N)cin >> V[i].first >> V[i].second;
    sort(V.begin(),V.end(),sor);
    P ans = P(0,-1);
    for(int i=0;i<N;i++){
        int max = 0;
        for(int j=0;j<N;j++){
            if(!used[j] && max<V[j].first && i>=V[j].second){
                max = V[j].first;
                ans.second = j;
            }
        }
        used[ans.second] = true;
        ans.first += max;
    }
    cout << ans.first << endl;
    return 0;
}