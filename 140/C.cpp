#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int A[100005];
int B[100001];
int main(){
    int N;cin >> N;
    rep(i,N-1){
        cin >> B[i];
    }
    A[0] = B[0];
    for(int i=1;i<N-1;i++){
        A[i] = min(B[i],B[i-1]);
    }
    if(N-2>=0){
    A[N-1] = B[N-2];
    }
    ll ans = 0;
    for(int i=0;i<N;i++){
        ans += A[i];
        //cout << A[i] << endl;
    }
    cout << ans << endl;
    return 0;

}