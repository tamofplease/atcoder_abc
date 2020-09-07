#include <iostream>

using namespace std;
typedef long long ll;
ll N,M;
void solve(){
    if(N>=M*2){
        cout<< M << endl;
        return;
    }
    ll count=  0;
    if(M>=N*2){
        count += N;
        count += (M-N*2)/3;
    }
    cout << count << endl;
    return ;
}

int main(){
    cin >> N >> M ;
    solve();
    return 0;
}