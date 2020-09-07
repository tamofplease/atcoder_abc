#include <iostream>

using namespace std;

int main(){
    int K,S;
    cin >> K >> S;
    int X,Y,Z;
    int count = 0;
    for(int i = 0;i<=K;i++){
        for(int j = 0;j<=K;j++){
            if(K>= S-i-j&&S-i-j >= 0 )count++;
        }
    }
    cout << count << endl;
    return 0;

}