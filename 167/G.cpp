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

int N;
const int MAXN=1000001;
string S[MAXN];

typedef pair<int,int> pa; // "(, )"

pa Pair[MAXN];



int compare_int(const int a , const int b) {
    if (a < b) {
        return 1;
    } else if (a > b) {
        return -1;
    }
    return 0;
}

// bool comp_pair_desc(const void *a,const void *b) 
// { 
//     const pa* num1 = (const pa *)a;
//     const pa* num2 = (const pa *)b;
//     return (num1->second == num2->second) ? false : (num2->second - num1->second) ;
// }

 bool comp_pair_desc(const pa& a,const pa& b) 
{ 
    return (a.first == b.first) ? false : (b.first - a.first) ;
}



bool comp_pair_acs(const pa& a,const pa& b) 
{ 
    return (a.second == b.second) ?   false : (a.second - b.second) ;
}

stack<string> sta;

string pop_brack(string s) {   
    string S;
    int len = s.length();
    for(int j=0;j<len;j++) {
        if(s[j]=='('){
            sta.push("(");
        }else if(s[j]==')') {
            if(!sta.empty() && sta.top()=="(")sta.pop();
            else sta.push(")");
        }
    }
    int length = sta.size();
    for(int j=0;j<length;j++) {
        S += sta.top();sta.pop();
    }
    for (int i = 0; i < length / 2; i++) swap(S[i], S[length - i - 1]); 

    return S;
}


int countRight(string s) {
  int count = 0;
  int len = s.length();
  rep(i,len)if(s[i]=='(')count++;
  return count;
}

int countLeft(string s) {
  int count = 0;
  int len = s.length();
  rep(i,len)if(s[i]==')')count++;
  return count;
}
        

int main(){

  cin >> N;
  rep(i,N){
    cin >> S[i];
  }

  rep(i,N) {
    S[i] = pop_brack(S[i]);
    Pair[i].first = countRight(S[i]);
    Pair[i].second = countLeft(S[i]);
    cout << Pair[i].first << " " << Pair[i].second << endl;
  }

  

  sort(Pair,Pair+N, comp_pair_desc);
  sort(Pair+(N/2),Pair+N,comp_pair_acs);
  rep(i,N)cout << Pair[i].first << " " << Pair[i].second << endl;
  
  ll tmp =0;

  rep(i,N){
    tmp += Pair[i].first;
    tmp -= Pair[i].second;
    if(tmp < 0){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
 
  return 0;
}