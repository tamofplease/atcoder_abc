#include <iostream>

using namespace std;

int main(){
  int A[4][4];
  bool ok[4][4];
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> A[i][j];
      ok[i][j] = false;
    }
  }
  int N;
  cin >> N;
  
  int b[11];
  for(int i=0;i<N;i++){
    cin >> b[i];
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        if(b[i] == A[j][k])ok[j][k] = true;
      }
    }
  }
  bool tmp = false;
  for(int i=0;i<3;i++){
    int count = 0;
    for(int j=0;j<3;j++){
      if(ok[i][j])count++;
      if(count==3){
        tmp = true;
        break;
      }
    }
  }
  for(int i=0;i<3;i++){
    int count = 0;
    for(int j=0;j<3;j++){
      if(ok[j][i])count++;
      if(count==3){
        tmp = true;
        break;
      }
    }
  }
  int count = 0;
  for(int i=0;i<3;i++){
    if(ok[i][i])count++;
    if(count==3){
      tmp = true;
      break;
    }
  }
  count = 0;
  for(int i=0;i<3;i++){
    if(ok[i][2-i]){
      count++;
    }
    if(count==3){
      tmp = true;
      break;
    }
  }

  if(tmp)cout << "Yes" << endl;
  else cout << "No" << endl;


  return 0;
}