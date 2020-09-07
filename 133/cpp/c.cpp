#include <iostream>

using namespace std;
typedef long long ll;
int main(){
    int  L,R;
    cin >> L >> R;
    if(R-L>=2019)cout << 0<< endl;
    else{
        ll mi = 2018;
        L %= 2019;
        R %= 2019;
        for(ll i=L;i<=R;i++){
            for(ll j=i+1;j<=R;j++){
                if(i>=j)continue;
                mi = min(mi,i*j%2019);
            }
        }
        cout << mi << endl;
    }
    return 0;
}