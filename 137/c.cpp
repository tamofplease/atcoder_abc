#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>

using namespace std;

typedef long long ll;

int main(){
    int N;
    cin >> N;
    set<string> s;
    set<string>::iterator ite;
    map<string,int> m;
    ll count = 0;
    for(int i=0;i<N;i++){
        string s1;
        cin >> s1;
        sort(s1.begin(),s1.end());
        if(s.empty()){
            s.insert(s1);
            m[s1] = 0;
        }else{
            ite=s.find(s1);
            if(ite!=s.end()){
                m[s1]++;
                count += m[s1];
            }else{
                s.insert(s1);
                m[s1]=0;
                
            }
        }
    }
    cout << count << endl;
    return 0;
}
