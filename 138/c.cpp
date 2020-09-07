#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long v[51];

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> v[i];
    }
    sort(v,v+N);
    long double sum = 0;
    long long div = 2;
    for(int i=N-1;i>0;i--){
        sum += (long double)v[i]/div;
        div*=2;
    }
    sum += v[0]/(div/2);
    cout << sum << endl;
    return 0;
}