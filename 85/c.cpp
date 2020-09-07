#include <iostream>

using namespace std;

int main(){
    int N;
    int Y;
    cin >> N >> Y ;
    int count = 0;
    int i,j,k;
    Y = Y/1000;
    for(i=0;i<=N;i++){
        for(j = 0;j<=N-i;j++){
            for(k = 0;k<=N-i-j;k++){
                if(k+j+i==N && i+5*j+10*k == Y)goto tag;
            }

        }
    }tag:
    if(i<0||j<0||k<0||i+j+k != N || k*10+j*5+i != Y){
        j = i = k = -1;
    }
    cout << k << " "<<j <<" " <<  i << endl;
    return 0;
}