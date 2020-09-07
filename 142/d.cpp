#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll A,B;
ll gcd(ll a,ll b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main(){
    cin >> A >> B;
    ll u = gcd(A,B);
    ll count = 0;
    for(ll i = 2;i*i<u;i++){
        if(u%i==0){
            count++;
            while(u%i==0){
                u /= i;
            }
        }
    }
    if(u!=1)count++;
    cout << count+1 << endl;
    return 0;

}