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


int N;
#define MAXN 8
int P[MAXN],Q[MAXN];


int main(){
    cin >> N;
    rep(i,N){
        cin >> P[i];
    }   
    rep(i,N)cin >> Q[i];
    int sample[MAXN];
    rep(i,N)sample[i] = i+1;
    sort (sample,sample+N);
    int numP,numQ;
    int count = 0;
    do {
        int countP = 0;
        int countQ = 0;
        count++;
        for(int i=0;i<N;i++){
            if(sample[i]==P[i]){
                countP++;
            }else{
                countP = 0;
            }
            if(sample[i]==Q[i]){
                countQ++;
            }else{
                countQ = 0;
            }
            if(countP==N)numP = count;
            if(countQ==N)numQ = count;
        }
    } while ( next_permutation(sample,sample+N) );
    
    cout << abs(numP-numQ) << endl;
    return 0;
}