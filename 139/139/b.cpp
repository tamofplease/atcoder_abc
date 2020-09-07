#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int A;
    int B;
    cin  >> A >> B;
    int ans = 1;
    int count = 0;
    while(true){
        if(ans>=B)break;
        ans -=1;
        ans += A;
        count ++;
    }
    
    cout << count << endl;
    return 0;

}