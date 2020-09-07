#include <iostream>

using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
void make(int s){
    for(int i=1;i<=9;i++){
        if(s%i==0){
            int r = s/i;
            if(r<10)cout << i << " x " << r << endl;
        }
    }
}
int main(){
    int N;cin >> N;
    int ans = 0;
    rep(i,9)rep(j,9){
        ans += i*j;
    }
    int key = ans - N;
    make(key);
    return 0;
}