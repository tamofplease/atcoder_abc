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

#define MAXN 16
int Q[MAXN][MAXN];//i番目の人がいうj番目がどういう状態か
int N;
int A[MAXN];//i番目の人の証言の数
int tmp[MAXN];
bool flag = 0;
void set_data(){
    cin >> N;
    rep(i,MAXN)rep(j,MAXN)Q[i][j] = 2;
    rep(i,N){
        cin >> A[i];
        rep(j,A[i]){
            int a;
            cin >> a;
            a--;
            cin >> Q[i][a];
        }
    }
    return ;
}

int main(){
    set_data();
    if(N==1&&A[0]==0)flag = 1;
    int ans = 0;
    int count = 0;
    int j;
    for(int i=0;i<(1<<N);i++){
        rep(l,MAXN)tmp[l] = 2;
        for(j=0;j<N;j++){
            if(i&(1<<j)){
                count++;
                if(tmp[j]==0)j = N*2;
                tmp[j] = 1;

                //j番目の人が正直だと仮定
                for(int k=0;k<N;k++){
                    if(Q[j][k]==2){
                    }else if(tmp[k]==2){
                        tmp[k] = Q[j][k];
                    }else if(tmp[k]!=Q[j][k])j = N*2;
                }
            }else{
                if(tmp[j]==2)tmp[j] = 0;
                if(tmp[j]==1){
                    j = N*2;
                }
                //j番目の人は嘘つきと仮定している
            }
        }
        if(j<N+1){
            ans = max(ans,count);
        }
        count = 0;
    }
    if(flag)cout << 1 << endl;
    else cout << ans << endl;
    return 0;
}