#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <queue>
#include <tgmath.h>
#define MOD 1000000007
using namespace std;

#define INT_MAX 2147000000
#define LONG_MAX 9223372036854775806

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
double A,B,C;
bool f(double t){
    return A*t+B*sin(C*t*M_PI)>100;
}
double checker(double a){
    return A*a+B*sin(C*a*M_PI);
}
int main(){
    cin >> A >> B >> C;
    double mi = 0;
    double ma = 10000000;
    while(ma-mi>0.0000000001){
        double mid = (mi+ma)/2;
        if(f(mid))ma = mid;
        else mi = mid;
    }
    cout << setprecision(12) <<  ma << endl;
    return 0;   
}