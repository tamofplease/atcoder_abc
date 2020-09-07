#include <iostream>
#include <string>
#include <map>
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

int main(){
    int a;
    int tmp = 0;
    cin >> a;
    for(int i=1;i<=9;i++)for(int j=1;j<=9;j++){
        if(a==i*j){
            tmp =1;
            break;
        }
    }
    if(tmp==1)puts("Yes");
    else puts("No");
    return 0;
}