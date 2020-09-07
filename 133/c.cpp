#include <iostream>

using namespace std;
typedef long long ll;
#define MOD 2019
int main(){
    ll L,R;
    cin >> L >> R;
    int ans = 2019;
    if(R-L>=2019)ans = 0;
    else {
        for(int i=L;i<=R;i++){
            for(int j=L;j<=R;j++){
                if(i<j){
                    if((i*j)%MOD<ans){
                        ans = (i*j)%MOD;
                    }
                }
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}