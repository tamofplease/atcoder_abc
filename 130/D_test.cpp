#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;
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


std::vector<std::string> split(std::string str, char del) {
    int first = 0;
    int last = str.find_first_of(del);
 
    std::vector<std::string> result;
 
    while (first < str.size()) {
        std::string subStr(str, first, last - first);
 
        result.push_back(subStr);
 
        first = last + 1;
        last = str.find_first_of(del, first);
 
        if (last == std::string::npos) {
            last = str.size();
        }
    }
 
    return result;
}
const int MAXN = 100000;
int a[MAXN];
int N = -1,K = -1;
int counter = 0;

void set_data() {
  string file;
  ifstream ifs("testdata", ios::in);
  string tmp,str;
  int num,sum = 0;
  while(getline(ifs, tmp)){
        vector<string> s = split(tmp, ' ');
        for(int i=0;i<s.size();i++) {
          int x = atoi(s[i].c_str());
          // cout << x << endl;
          if(N==-1)N = x;
          else if(K==-1)K = x;
          else a[counter++] = x;
        }
  }
  ifs.close();
}



int main(){
    int front=0,back=0;
    set_data();
    // cin >> N >> K;
    // rep(i,N)cin >> a[i];
    ll tmp = 0;
    ll ans = 0;
    while(1) {
        if(tmp >= K) {
            ans += N - front + 1;
            back++;
            front = back;
            tmp = 0;
        }
        if(front==N && tmp < K)break;
        tmp += a[front];
        front++;
    }

    cout << ans << endl;


    return 0;
}