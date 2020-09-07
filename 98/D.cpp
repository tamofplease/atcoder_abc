#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <tgmath.h>
#define MOD 1000000007
using namespace std;

#define INT_MAX 2147000000
#define LONG_MAX 9223372036854775806

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int N;
int main(){
    cin >> N;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    ll right = 0;
    ll sum = 0;
    ll xor = 0;
    ll ans = 0;
    rep(left,N){
        while((xor^A[right])==(sum+A[right])&&right<N){
            sum += A[right];
            xor 
            right++;
        }
        ans += right-left;
        if(left==right)right++;
        else{
            sum -= A[left];
        }
    }
    cout << ans << endl;
    return 0;
}