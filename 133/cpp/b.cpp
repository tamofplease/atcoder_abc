#include <iostream>
#include <math.h>
using namespace std;
int N,D;
#define rep(i,N) for(int i=0;i<N;i++)
int X[11][11];
int main(){
    cin >> N >> D;
    rep(i,N){
        rep(j,D){
            cin >> X[i][j];
        }
    }
    int count = 0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            double sum = 0;
            for(int k=0;k<D;k++){
                sum += pow(X[i][k]-X[j][k],2);
            }
            if(sqrt(sum)==(int)sqrt(sum)){
                count++;
        }
        }
    }
    cout << count << endl;
}