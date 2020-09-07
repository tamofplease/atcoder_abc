#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
long double A[1001];
int main(){
    cin >> N;
    long double sum = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        sum += 1/A[i];
    }
    
    printf("%0.6Lf",1/sum);
    return 0;
}