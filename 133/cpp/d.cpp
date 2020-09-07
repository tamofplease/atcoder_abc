#include <iostream>

using namespace std;
typedef long long ll;
ll N;
#define MAXN 1000001
ll A[MAXN];
int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    A[N] = A[0];
    ll B[MAXN];
    B[0] = 0;
    for(int i=0;i<N;i++){
        B[i+1] = -B[i]+2*A[i];
    }
    if(B[N]!=B[0]){B[0] = B[N]/2;
        for(int i=0;i<N;i++){
            B[i+1] = -B[i]+2*A[i];
        }
    }
    for(int i=0;i<N;i++){
        cout << B[i] << ' ';
    }
    cout << endl;
    return 0;
}