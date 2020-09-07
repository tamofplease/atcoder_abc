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

const int MAXN = 100001;
int main(){
    int N,K;cin >> N >> K;
    string S;
    cin >> S;
    int ans = 0;
    bool one;
    if(S[0]=='1')one=true;
    else one = false;
    int SA[MAXN];
    memset(SA,0,sizeof(SA));
    int cur=0;
    bool ones[MAXN];
    rep(i,N){   
        if(one && S[i]=='1'){
            SA[cur]++;
            ones[cur]=true;
        }
        else if(!one && S[i]=='0'){
            ones[cur] = false;
            SA[cur]++;
        }
        else{
            one = !one;
            cur++;
            SA[cur]++;
            ones[cur]=one;
        }
    }

    int front = 0;int back = 0;
    
    int tmp = K;
    int ma = 0;
    while(front<=cur){
        while(tmp>0 || ones[front]){
            if(!ones[front])tmp--;
            ans += SA[front];
            front++;
            ma = max(ma,ans);
        }
        if(!ones[back])tmp++;
        ans -= SA[back];
        back++;
    }

    
    cout << ma << endl;

    return 0;
}