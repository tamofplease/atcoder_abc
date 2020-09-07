#include <iostream>
#include <map>
#include <string>
#include <algorithm>
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

int N;
#define MAXN 200001
string S[MAXN];
int main(){
    cin >> N;
    rep(i,N)cin >> S[i];
    map<string,int>M;
    int maxn = 0;
    rep(i,N){
        auto itr = M.find(S[i]);
        if(itr == M.end()){
            M[S[i]] = 1;
            if(maxn < M[S[i]])maxn = M[S[i]];
        }else{
            M[S[i]]++;
            if(maxn < M[S[i]])maxn = M[S[i]];
        }
    }
    string A[MAXN];
    int count =0;
    rep(i,N){
        if(M[S[i]]==maxn){
            A[count] = S[i];
            count++;
        }
    }

    sort(A,A+count);
    for(int i=0;i<count;i+=maxn){
        cout << A[i] << endl;
    }

    return 0;
}