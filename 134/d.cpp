#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#define MOD 1000000007
#define INT_MAX 2147000000
#define LONG_MAX 9223372036854775806
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
template<int mod=MOD> class modint {
private:
  int _num;
  modint set(int num){ _num = num % mod; return *this; }
public:
  modint(){ _num = 0; }
  modint(int num){ _num = num % mod; }

  modint operator= (int x){ return set(x % mod); }
  modint operator+ (int x){ return modint<mod>(_num + (x % mod)); }
  modint operator- (int x){ return modint<mod>(_num - (x % mod)); }
  modint operator* (int x){ return modint<mod>(_num * (x % mod)); }
  modint operator+=(int x){ return set(_num + (x % mod)); }
  modint operator-=(int x){ return set(_num - (x % mod)); }
  modint operator*=(int x){ return set(_num * (x % mod)); }

  explicit operator int() { return _num; }
  friend ostream& operator<<(ostream &os, const modint<mod> &x){ os << x._num; return os; }
};

int N;
#define MAXN 200001
int A[MAXN];
int B[MAXN];
void check(int a,int s){
    for(int i=2;i*i<=a;i++){
        if(a%i==0){
            if(a/i!=i){
                B[a/i]++;
            }
            B[i]++;
        }
    }
}
int main(){
    cin >> N;
    priority_queue<int,vector<int>,greater<int> > PQ;
    for(int i=1;i<=N;i++){
        cin >> A[i];
        B[i] = 0;
    }
    int count = 0;
    for(int i=N;i>0;i--){
        if(A[i]!=B[i]%2){
            B[1]++;
            B[i]++;
            PQ.push(i);
            check(i,2);
            count++;
        }
    }
    cout << count << endl;
    bool t = false;
    rep(i,count){
        cout << PQ.top()<<" ";
        PQ.pop();
        t = true;
    }
    if(t)cout << endl;
    return 0;
}