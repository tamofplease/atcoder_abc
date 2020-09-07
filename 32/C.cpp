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
int n,K;
#define MAXn 100001
int a[MAXn];
int main(){
    bool ok = false;
    cin >> n >> K;
    int res = 0;
    int right = 0;
    ll mul = 1;
    int ans = 0;
    rep(i,n){
        cin >> a[i];
        if(a[i]==0){
            ok = true;
            res = n;
        }
    }
    if(!ok){
        for(int left = 0;left<n;left++){
            while(right<n&&mul*a[right]<=K){
                mul *= a[right];
                right++;
            }
            res = max(res,right-left);
            if(left==right)++right;
            else mul /= a[left];
        }
    }
    cout << res << endl;
    return 0;
}