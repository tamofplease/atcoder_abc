#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int Q;
#define MAX 100001
int l[MAX],r[MAX];
bool prime[MAX];
int main(){
    cin >> Q;
    fill(prime,prime+MAX,true);
    prime[0] = false;
    prime[1] = false;
    for(int i=2;i*i<=MAX;i++){
        if(prime[i]){
            for(int j=2;j*i<=MAX;j++){
                prime[i*j]=false;
            }
        }
    }
    bool ans[MAX];
    for(int i=0;i<=MAX;i++){
        if(i%2==1&&prime[i]&&prime[(i+1)/2]){
            ans[i] = true;
        }else{
            ans[i] = false;
        }
    }
    int anse[MAX];
    fill(anse,anse+MAX,0);
    for(int i=1;i<MAX;i++){
        if(ans[i]){
            anse[i] = 1;
        }
        anse[i] += anse[i-1];
    }
    rep(i,Q){
        cin >> l[i] >> r[i];
    }
    rep(i,Q){
        cout << anse[r[i]]-anse[l[i]-1]<< endl;
    }
    return 0;

}