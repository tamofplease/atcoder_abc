#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
int N;
#define MAXN 100001
ll A[MAXN];
int main(){
    cin >> N;
    rep(i,N){
        cin >> A[i];
    }
    char a = 3;
    char b = 5;
    cout << a^b << endl;
    return 0;

}