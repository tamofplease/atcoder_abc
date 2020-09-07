#include <iostream>
#include <math.h>
using namespace std;

int main(){
    for(int n=1;n<=20;n++){
    double bun = 0;
    double ans = double(double(25)/double(4));
    for(int i=0;i<n;i++){
        if((i+1)%2==1)bun += (double)1/(double)((i+1)*(1+i));
    }

    ans -= bun*(50/((M_PI)*(M_PI)));
    if(n%2==0)printf("%.11f\n",ans);
    }
    return 0;
}