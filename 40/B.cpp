#include <iostream>

using namespace std;

int solve(int i,int j,int k){
    int one = abs(i-j);
    return one + k;
}

int main(){
    int N;
    cin >> N;
    int ans = 1000000;
    for(int i=1;i<N;i++){
        int j = N/i;
        int k = N-(i*j);
        ans = min(ans,solve(i,j,k));

    }
    ans = ans==1000000 ? 0 : ans;
    cout << ans << endl;
    return 0;
}