#include <iostream>
#include <string>
#include <set>
using namespace std;
string s;
int k;
set<string> st;
void solve(){
    int l = s.length();
    if(k>l){
        cout << 0 << endl;
        return;
    }
    for(int i=0;i<=l-k;i++){
        string tmp = s.substr(i,k);
        st.insert(tmp);
    }
    cout << st.size() << endl;
    return ;
}
int main(){
    cin >> s >> k;
    solve();
    return 0;
}