#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int N,D;
int main(){
    cin >> N >> D;
    if(N%(2*D+1)==0)cout << N/(2*D+1) << endl;
    else cout << N/(2*D+1)+1 << endl;
    return 0;

}