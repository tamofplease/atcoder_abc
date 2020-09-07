#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int A,B,C,D;
int main(){
    cin >> A >> B >> C >> D;
    cout << max(0,min(B,D)-max(A,C)) << endl;
    return 0;

}