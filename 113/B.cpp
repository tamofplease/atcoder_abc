#include <iostream>
#include <math.h>

using namespace std;
#define MAXN 1002
int main(){
    int N;
    int T,A;
    double H[MAXN+1];
    cin >> N >> T >> A;
    for(int i=1;i<=N;i++){
        cin >> H[i];
        H[i] = fabs(A - (T-H[i]*0.006));
    }
    int num = 1;
    for(int i=2;i<=N;i++){
        if(H[num]>H[i]){
            num = i;
        }
    }
    cout << num << endl;
    return 0;

}