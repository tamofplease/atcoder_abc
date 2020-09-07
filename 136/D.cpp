#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

long long modinv(long long a, long long m=MOD) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
    /*MODの割り算の際に
    a/＝b;
    を
    a *= modinv(b,MOD);
    とする。
    */
}

string S;

int main(){
    cin >> S;
    int N = S.length();
    vector<int> Data(N,0);
    int count = 0;
    int odd = 0,even = 0;
    int oddmem,evenmem;
    for(int i=0;i<N;i++){
        if(i%2==0)odd++;
        else even++;
        count++;
        if(i!=(N-1)&&S[i]=='R'&&S[i+1]=='L'){
            if(i%2==0){
                oddmem = i;
                evenmem = i+1;
            }else{
                oddmem = i+1;
                evenmem = i;
            }
        }
        if(i!=(N-1)&&S[i]=='L'&&S[i+1]=='R'){
            Data[oddmem] = odd;
            Data[evenmem] = even;
            oddmem = 0;
            evenmem = 0;
            odd = 0;
            even = 0;
        }else if(i==N-1){
            Data[oddmem] = odd;
            Data[evenmem] = even;
        }
    }
    rep(i,N)cout << Data[i] << " ";
    cout << endl;
    return 0;
}