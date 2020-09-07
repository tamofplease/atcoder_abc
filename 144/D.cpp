#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <float.h>
#include <tgmath.h>
#define MOD 1000000007
using namespace std;
#define INT_MAX 2147000000
#define LONG_MAX 9223372036854775806

typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    double a,b,x;
    cin >> a >> b >> x;
    ll s = a*a;
    ll tai = a*a*b;
    double amari = tai-x;
    double T;
    
    if(tai<x*2){
    T = (amari*2.0)/(a*a*a);
    }else{
        T = (a*b*b)/(2*x);

    }
    
    double front = 0;
    double back = M_PI/2;
    double i;
    for(int j=0;j<1000000;j++){
        i = (front+back)/2;
        if(T<tan(i))back = i;
        else front = i;
    }
    
    i *= (180/M_PI);
    printf("%2.8f\n",i);
    return 0;
}