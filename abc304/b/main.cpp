#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n < 1000) cout << n << '\n';
    if (1000 <= n && n <= 9999) cout << n - n % 10 << '\n';
    if (10000 <= n && n <= 99999) cout << n - n % 100 << '\n';
    if (100000 <= n && n <= 999999) cout << n - n % 1000 << '\n';
    if (1000000 <= n && n <= 9999999) cout << n - n % 10000 << '\n';
    if (10000000 <= n && n <= 99999999) cout << n - n % 100000 << '\n';
    if (100000000 <= n && n <= 999999999) cout << n - n % 1000000 << '\n';
}