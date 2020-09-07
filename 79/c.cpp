#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main(){
    string s;
    vector<char> as;
    cin >> s;
    int l = s.size();
    for(int i=0;i<(1<<(l-1));i++){
        int ans = s[0]-'0';
        vector<char> v;
        v.push_back(s[0]);
        for(int j=1;j<l;j++){
            if(i&(1<<(j-1))){
                ans +=(s[j]-'0');
                v.push_back('+');
                v.push_back(s[j]);
            }else{
                ans -=(s[j]-'0');
                v.push_back('-');
                v.push_back(s[j]);
                
            }
        }
        if(ans==7){
            as = v;
            break;
        }
    }
    for(int i=0;i<as.size();i++){
        cout << as[i];
    }
    cout << "=7"<< endl;
}
