#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;

int main(){
    ll K,X;
    cin >> K >> X;
    for(ll i= X-K+1;i<X+K;i++){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}