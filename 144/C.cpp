#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <math.h>
#define MOD 1000000007
using namespace std;
#define INT_MAX 2147000000
#define LONG_MAX 9223372036854775806

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll num[1000];
int main(){
    ll N;
    ll count = 0;
    cin >> N;
    ll sp = sqrt(N);
    ll a = 1,b = 1;
    for(int i=sp+1;i>1;i--){
        if(N%i==0){
            while(N%i==0){
            N/=i;
            num[count] = i;
            count++;
            }
        }
    }
    
    if(N!=1){
        num[count] = N;
        count++;
    }
    for(ll i=0;i<count;i++){
        if(b>=a)a*=num[i];
        else b*= num[i];
    }
    cout << a+b-2 << endl;
    return 0;
}