#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 100001
string S[MAXN];

int main(){
    int N;
    cin >> N;
    long long ans = 0;
    map<string,int> MA;
    for(int i=0;i<N;i++){
        cin >> S[i];
        sort(S[i].begin(),S[i].end());
        MA[S[i]]++;
        ans += MA[S[i]]-1; 
    }

    
    
        cout << ans << endl;

    return 0;
}