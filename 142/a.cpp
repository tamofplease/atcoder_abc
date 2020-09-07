#include <iostream>

using namespace std;

int main(){
    int N;cin >> N;
    if(N%2==0)cout << 0.5000000 << endl;
    else{
        printf("%.8f",(double)(N/2+1)/N);
    }
    return 0;
}