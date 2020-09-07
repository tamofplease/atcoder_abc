#include <iostream>
#include <string>
using namespace std;

int N,M;
int s[6],c[6];
#define rep(i,N) for(int i=0;i<N;i++)

bool ok = true;

unsigned GetDigit(unsigned num){
    unsigned digit=0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

string change(int s){
  string str;
  int i = 0;
  while(true){
    str.push_back(s%10);
    s/=10;
    
    if(s==0)break;
  }
  return str;
}

void solve(){
  cin >> N >> M;

  rep(i,M){
    cin >> s[i] >> c[i];
    for(int j=0;j<i;j++){
      if(s[i]==s[j] && c[i]!=c[j]){
        ok = false;
      }
    }
  }
  if(!ok){
    cout << -1 << endl;
    return ;
  }
  
  int ans =  0;
  for(int i=0;i<=999;i++){
    ok = true;

    if(GetDigit(i)==N){
      string str = change(i);
      cout << str << endl;
      for(int j=0;j<M;j++){
        if(str[s[j]-1]!=c[j])ok = false;
        
        if(j==(M-1) && ok){
          ans = i;
          break;
        }
      }
    }
  }
  if(ok)cout << ans << endl;
  else cout << -1 << endl;
}

int main(){
  solve();
  
  return 0;
}