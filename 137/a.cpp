#include <iostream>
#include <vector>
#include <string>
typedef long long ll;

using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int A = a+b;
    int B = a-b;
    int C = a*b;
    int D = a-b;
    int am,bm;
    if(A > B){
    am = A;
    }else am = B;
    if(C>D){
        bm = C;
    }else bm = D;
    if(am>bm){
        cout << am << endl;
    }else cout << bm << endl;
    return 0;
}