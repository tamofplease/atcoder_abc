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

int countDigit(int n)
{
  int digit = 1;
  while((n /= 10) != 0)digit++;
  return digit;
}

int swap(int a){
    string S = to_string(a);
    int len = S.length();
    char tmp = S[0];
    S[0] = S[len-1] ;
    S[len-1] = tmp;
    return  stoi(S);
}

int N;
#define MAXN 200000
int data[100] = {0};
int ans  =0;
int first(int a){
    string S = to_string(a);
    return S[0] - '0';
}
int last(int a){
    string S = to_string(a);
    int len = S.length();
    return S[len-1] - '0';
}

void solve(){
    for(int i=1;i<=N;i++){
        int tmp = first(i)*10 + last(i);
        if(i>10 && first(i) == last(i)){
            data[tmp] += 1;
        }else data[tmp] += 1;
        
    }
}

int main(){
    cin >> N;
    solve();
    ans = 0;
    for(int i=1;i<100;i++){
        if(i==swap(i)){
            ans += data[i]*data[i];
        }else ans += data[i]*data[swap(i)];
    }
    cout << ans << endl;
    return 0;
}