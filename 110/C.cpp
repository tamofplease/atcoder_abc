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
long long modinv(long long a, long long m=MOD) {long long b = m, u = 1, v = 0;while (b) {    long long t = a / b;    a -= t * b; swap(a, b);    u -= t * v; swap(u, v);}u %= m; if (u < 0) u += m;return u;}
//MODの割り算の際にa/＝b;をa *= modinv(b,MOD);とする。
int gcd(int a, int b){if (a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}
 
int main(){
    string S,T;cin >> S >> T;
    int len = S.length();
    map<char,char> ma;
    map<char,char> m;
    rep(i,len){
        if(ma.find(T[i])== ma.end()){
            ma[T[i]] = S[i];
        }else{
            if(ma[T[i]] != S[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    rep(i,len){
        if(m.find(S[i])== m.end()){
            m[S[i]] = T[i];
        }else{
            if(m[S[i]] != T[i]) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}