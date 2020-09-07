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

const int maxq = 200001;

int T[maxq];
int F[maxq];
char C[maxq];

int main(){
    string s;int q;

    cin >> s >> q; 
    
    bool reverse = false;
    int j = 0;
    rep(i,q) {
        cin >> T[i];
        if(T[i] == 1) {
            reverse = !reverse; 
        }else {
            cin >> F[j] >> C[j];
            j++;
        }
    }
    if(reverse)std::reverse(s.begin(), s.end());
    std:deque<char> deq;
    rep(i,s.length()) {
        deq.push_back(s[i]);
    }
    reverse = !reverse;
    j = 0;
    rep(i,q) {
        if(T[i] == 1) {
            reverse = !reverse; 
        }else {
            if(reverse) {
                if(F[j] == 1) deq.push_front(C[j]);
                else deq.push_back(C[j]);
            }else {
                if(F[j] == 1) deq.push_back(C[j]);
                else deq.push_front(C[j]);
            }
            j++;
        }
    }
    if(reverse) {
        std::for_each(deq.begin(), deq.end(), [](char x) {
            std::cout << x ;
        });
    }else{
        std::reverse_iterator<decltype(deq)::iterator> first(deq.end());
        std::reverse_iterator<decltype(deq)::iterator> last(deq.begin());
        std::for_each(first, last ,[](char x) {
            std::cout << x ;
        });
    }
    cout << endl;
    return 0;
}