#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int N;
#define MAXN 200001
ll A[MAXN];
int main(){
    ll MAX = 0;
    ll MAX2 = 0;
    cin >> N;
    rep(i,N){
        cin >> A[i] ;
        if(A[i]>MAX2){
            if(A[i]>MAX){
            MAX = A[i];
        }else{
            MAX2 = A[i];
        }
        }
        
    }
    rep(i,N){
        if(A[i]==MAX)cout << MAX2 << endl;
        else cout << MAX << endl;
    }
    return 0;

}