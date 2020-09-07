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
    int N;
    cin >> N;
    const int MAXN = 100001;
    int A[MAXN];
    rep(i,N){
        cin >> A[i];
    }

    map<int,int> odd;
    map<int,int> even;
    int odd_max = 0;
    int second_odd = 0;
    int second_even = 0;
    int even_max = 0;
    int odd_num,even_num;
    rep(i,N){
        if(i%2==0){
            if(odd.count(A[i])==0){
                odd[A[i]] = 1;
            }else{
                odd[A[i]]++;
            } 
            if(odd_max < odd[A[i]]){
                odd_max = odd[A[i]];
                odd_num = A[i];
            }
            
        }else {
            if(even.count(A[i])==0){
                even[A[i]] = 1;
            }else {
                even[A[i]]++;
            }
            if(even_max < even[A[i]]){
                even_max = even[A[i]];
                even_num = A[i];
            }
        }
    }
    rep(i,N){
        if(odd_num != A[i] && second_odd < odd[A[i]]){
            second_odd = odd[A[i]];
        }
        if(even_num != A[i] && second_even < even[A[i]]){
            second_even = even[A[i]];
        }
    }
    int ans ;
    if(even_num == odd_num){
        if((odd_max + second_even) > (even_max + second_odd)){
            ans = N - odd_max - second_even;
        }else ans = N - even_max - second_odd;
    }else ans = N - even_max - odd_max;
    cout << ans << endl;
    return 0;
}