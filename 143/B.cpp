#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
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
#define MAXN 51
int d[MAXN];
int S[MAXN*MAXN];
int main(){
    cin >> N;
    
    int count = 0;
    rep(i,N)cin >> d[i];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i<=j)continue;
            S[count]=(d[i]*d[j]);
            count++;
        }
    }
    int ans = 0;
    for(int i=0;i<count;i++){
        ans += S[i];
    }
    cout << ans << endl;
    return 0;
}