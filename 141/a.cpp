#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    string S;
    cin >> S;
    if(S=="Sunny"){
        cout << "Cloudy" << endl;
    }else if(S=="Cloudy"){
        cout << "Rainy" << endl;
    }else{
        cout << "Sunny"<< endl;
    }
    return 0;

}