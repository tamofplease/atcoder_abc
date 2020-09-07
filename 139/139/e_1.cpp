#include <bits/stdc++.h>
using namespace std;
#define rep(i,f,n) for(int i=0;i<N;i++)
int main(){
    int N;cin >> N;
    vector<vector<int>> V(N+1);
    for(int i= 1;i<=N;i++){
        for(int j=1;j<N;j++){
            int k;
            cin >> k;
            V[i].push_back(k-1);
        }
    }
    int c[1001];
    bool k = true;
    long long count = 0;
    while(k){
        k = false;
        rep(i,1,N+1)if(c[i])k = true;
        if(!k)continue;
        rep(i,1,N+1)c[i]= false;
        for(int i=1;i<=N;i++){
            if(!c[i]){
                
                int now = V[i].front();
                cout << V[i].front();
                //cout << V[now].front() << endl;
                /*if(V[now].front() == i && !c[now]){
                    V.erase
                    c[i] = c[now] = true;
                }*/
            }
        }
        count++;
        bool emp = false;
        rep(i,1,N+1){
            if(!V[i].empty()){
                emp = true;
            }
        }
        if(!emp)break;
    }
    if(!k){
        cout << -1 << endl;
    }else{
        cout << count << endl;
    }
    return 0;
}