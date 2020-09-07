#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    if(s[0]=='a'&&s.length() == 1)cout << -1 << endl;
    else cout << "a" << endl;
    return 0;
}