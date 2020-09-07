#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    int N;cin >> N;
    vector<vector<int> > V(N+1,vector<int>(N+1));
    for(int i=0;i<N-1;i++){
        for(int j=0;j<N;j++){
            int k;cin>> k;
            V[i].push_back(k);
        }
    }
    rep(i,N-1){
        for(auto j:V[i]){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
