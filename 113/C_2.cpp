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
 
bool ser(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first != b.first)return a.first < b.first;
    return a.second < b.second;
}

int main(){
    int N,M;cin >> N >> M;
    vector<pair<int,int> > V;
    vector<pair<int,int>> V_2;
    map<pair<int,int>, int> Ma;
    rep(i,M){
        int a,b;cin >> a  >> b;
        V.push_back(make_pair(a,b));
        V_2.push_back(make_pair(a,b));
    }
    sort(V_2.begin(), V_2.end(),  ser);

    int before = 0;
    int count = 1;
    for(pair<int,int> i : V_2){
        if(before != i.first)count = 1;
        Ma[i] = count;
        count++;
        
        // cout << endl;
        // cout << i.first << " " << i.second << " " << Ma[i]<< endl;
        before = i.first;
    }


    rep(i,M){
        int num = Ma[V[i]];
        int ken = V[i].first;

        printf("%06d%06d\n",ken,num);

    }


    return 0;
}