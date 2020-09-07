#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int S[30000];

int main(){
    int N;
    cin >> N;
    vector<ll> S(N);
    priority_queue<ll,vector<ll> ,greater<ll>> P;
    for(ll i=0;i<(int)pow(2,N);i++){
                int k;cin >> k;
                P.push(k);
    }
    bool checker = true;
    for(ll j=1;j<=N;j++){
        if(N-j-1>=0){
        for(int i=0;i<pow(2,N-j-1);i++){
            P.pop();
        }
        }
        int la = P.top();
        P.pop();
        if(la==P.top()){
            //cout << la << P.top() << endl;
            checker = false;
            break;
        }
    }
    
    if(checker){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;

}