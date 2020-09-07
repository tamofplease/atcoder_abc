#include <iostream>

using namespace std;

int main(){
    string S,T;
    cin >> S >> T;
    int s = S.length(),t = T.length();
    bool checker = false;
    int tmp = 0;
    for(int i=s-1;i>=0;i--){
            checker = true;
            int k = i;
            for(int j=t-1;j>=0;j--){
                if(T[j]!=S[k]&&S[k]!='?'){
                    checker = false;
                }
                k--;
                if(j==0&&checker==true){
                    tmp = i;
                    goto tag;
                }
        }
    }tag:
    string ans;
    if(checker){
        int z = 0;
        for(int i=0;i<s;i++){
            if(i>tmp-t&&i<=tmp){
                ans.push_back(T[z]);
                z++;
            }else{
                if(S[i]=='?')ans.push_back('a');
                else   ans.push_back(S[i]);
            }
        }
        cout << ans << endl;
    }else{
        cout << "UNRESTORABLE" << endl;
    }

}