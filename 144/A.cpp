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
    int a,b;
    cin >>a >> b;
    if(a<10&&b<10)cout << a*b << endl;
    else cout <<  -1 <<endl;
    return 0;
}