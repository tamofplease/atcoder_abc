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
    int a;cin >>a;
    string s[101];
    map<string,int> ma;
    bool ok = true;
    rep(i,a){
        cin >> s[i];
        if(ma.count(s[i]) != 0){
            ok = false;
        }else {
            ma[s[i]] = 1;
        }
    }
    if(!ok){
        cout << "No" << endl;
        return 0;
    }
    char top;
    char tail;
    Rep(i,a-1){
        top = s[i][0];
        tail = s[i-1][s[i-1].length()-1];
        if(top != tail){
            cout << "No" << endl;
            return 0;
        }
    }
    
    rep(i,a){

    }
    cout << "Yes" << endl;

    return 0;
}