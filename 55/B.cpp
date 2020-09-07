#include <iostream>
using namespace std;

int N;
#define MOD 1000000007

int main(){
    cin >> N;
    long long Ans = 1;
    for(int i=1;i<=N;i++){
        Ans *= i;
        Ans = (Ans+MOD)%MOD;
    }

    cout << Ans << endl;
    return 0;
}