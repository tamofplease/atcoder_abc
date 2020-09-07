#include <iostream>

using namespace std;
typedef long long ll;
ll N,K;

#define MAXN 100000
#define rep(i,N) for(int i=0;i<N;i++)
ll s[MAXN];
#define INF 1000000001
void solve(){
    ll tmp = 1;
    ll front = 0,back = 0;
    ll length = 0;
    bool prog = true;
    while(front<N){
        if(tmp*s[front]<=K){
            tmp *= s[front];
            front++;
            prog = true;
        }else{
            prog = false;
        }
        if(front==back){
            front++;back++;
            continue;
        }
        length = max(length,front-back);
        if(!prog){
            tmp /= s[back];
            back++;
        }
    }
    cout << length << endl;
    return ;
}

int main(){
    bool check = false;
    cin >> N >> K;
    rep(i,N){
        cin >> s[i];
        if(s[i]==0){
            check = true;
        }
    }
    if(check)cout << N << endl;
    else{
        solve();
    }
    return 0;
}