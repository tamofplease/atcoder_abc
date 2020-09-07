#include <iostream>

using namespace std;

int main(){
    int N;cin >> N;
    int ma = 0;
    for(int i=0;i*i<=N;i++){
        ma = max(i*i,ma);
    }
    cout << ma << endl;
    return 0;
}