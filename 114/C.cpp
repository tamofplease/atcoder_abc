#include <iostream>

using namespace std;

long long N;

long long S[500000];

long long A[3] = {3,5,7};
long long count = 0;

long long ret_tri(long long a){
  long long tmp = 1;
  long long Z[11];
  long long num = 0;
  count = 0;
  while(true){
    Z[count] = a%4;
    if(Z[count]== 0){
      return 0;
    }
    num += A[Z[count]-1]*tmp;
    count++;
    tmp *= 10;
    a/=4;
    if(a==0)break;    
  }
  return num;
}

void Set_S(){
  long long number = 0;
  for(long long i=0;i<5000000;i++){
    long long tmp = ret_tri(i);
    if(tmp==0){
      continue;
    }
    long long tmp2 = tmp;
    bool one_a = false,two_a = false,three_a=false;
    bool ok = false;
    for(long long j=0;j<count;j++){
      if(tmp % 10 == 3)one_a = true;
      if(tmp % 10 == 5)two_a = true;
      if(tmp % 10 == 7)three_a = true;
      if(one_a && two_a && three_a)ok = true;
      tmp /= 10;
    }
    if(ok){
      S[number] = tmp2;
      number++;
    }
  }
}

int main(){
  cin >> N;
  Set_S();
  long long coun = 0;
  long long ans = 0;
  while(S[coun] <= N){
    coun++;
  }
  
  cout << coun << endl;
  return 0;
}