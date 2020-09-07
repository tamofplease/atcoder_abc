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
#define MAXN 100001

int main(){
    ll tmp = 0;
    ll right = 1;

    cin >> N;
    vector<ll> a(N);
    rep(i,N)cin >> a[i];
    rep(left,N){
        while(right<N&&(a[right-1]<a[right]||right<=left)){
            right++;
        }   
        tmp += right -left;
        if(left==right)right++;
    }
    cout << tmp << endl;
    return 0;
}