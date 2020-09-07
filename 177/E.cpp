#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

struct edge{
    int to,weight;
    edge(int to,int weight):to(to),weight(weight){}
};
using Graph = vector<vector<int>> ;
using GraphEdge = vector<vector<int>> ;

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
int gcd(int a, int b){if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}


//素因数分解で出てきた素数を全て挿入するvector
const int MAXN = 1000001;
const int hal = 10001;
int di[MAXN];
int Prime[MAXN];


int main() {
    int N;cin >> N;
    int A[MAXN];
    rep(i,N)cin >> A[i];
    memset(Prime,0,sizeof(Prime));
    for(int i=2;i<MAXN;i++){
        if(Prime[i]==0){
            Prime[i] = i;
            int tmp = i;
            while((tmp+i)<MAXN){
                tmp += i;
                if(Prime[tmp]==0)Prime[tmp] = i;
            }
        }
    }
    Prime[1] = 1;

    memset(di,0,sizeof(di));
    rep(i,N){
        if(Prime[A[i]] != A[i]){
            int tmp = A[i];
            while(tmp>1){
                di[Prime[tmp]]++;
                int pr = Prime[tmp];
                while(tmp%pr==0){
                    tmp /= pr;
                }
            }
        }else{
            di[A[i]]++;
        }
    }
    // di[0] = 0;
    // di[1] = 0;


    rep(i,MAXN){
        if(di[i]>1){
            int tmp = A[0];
            Rep(i,N-1){
                tmp = gcd(tmp,A[i]);
            }
            if(tmp==1){
                cout << "setwise coprime" << endl;
                return 0;
            }else {
                cout << "not coprime" << endl;
                return 0;
            }
        }
    }

    cout << "pairwise coprime" << endl;

    return 0;
}