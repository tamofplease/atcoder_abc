#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int A[100],B[100],C[100];
int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int k;cin >> k;
        A[i] = k-1;
    }
    for(int i=0;i<N;i++){
        cin >> B[i] ;
    }
    for(int i=0;i<N-1;i++){
        cin >> C[i] ;
    }
    int ans = 0;
    for(int i=0;i<N;i++){
        ans += B[A[i]];
        if(A[i+1]==A[i]+1){
            ans += C[A[i]];
        }
    }
    cout << ans << endl;
    return 0;

}