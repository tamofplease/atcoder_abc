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
    int N;
    string S;
    cin >> N >> S;
    int count =    1;
    for(int i=0;i<S.length()-1;i++){
        if(S[i]==S[i+1])continue;
        if(S[i]!=S[i+1])count++;
    }
    cout << count << endl;
    return 0;
}