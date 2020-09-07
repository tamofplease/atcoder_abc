#include <iostream>

using namespace std;

int main(){
    long long X,Y;
    cin >> X >> Y;
    long long  count = 1;
    long long tmp = X;
    while(true){
        tmp *= 2;
        if(tmp>Y)break;
        count++;
    }
    cout << count << endl;
    return 0;
}