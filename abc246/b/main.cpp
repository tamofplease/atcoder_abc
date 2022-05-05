#include <iostream>
#include <cmath>

using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
    int a, b; cin >> a >> b;
    a *= a; b *= b;
    double c = sqrt((double)a / (a + b));
    double d = sqrt((double)b / (a + b));
    printf("%.12f %.12f\n", c, d);
    return 0;
}