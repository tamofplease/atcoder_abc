#include <iostream>
#include <map>

using namespace std;
map<string,int> M;
int main(){
    int N;
    cin >> N;
    map<string,int>::iterator ite;
    
    for(int i=0;i<N;i++){
        string s;
        cin >> s;
        ite = M.find(s);
        if(ite==M.end()){
            M.insert(make_pair(s,1));
        }else{
            M[ite->first]++;
        }
    }
    int Ma;cin >> Ma;
    for(int i=0;i<Ma;i++){
        string s;
        cin >> s;
        ite = M.find(s);
        if(ite==M.end()){
            M.insert(make_pair(s,0));
        }else{
            if(M[ite->first]==0){
                M[ite->first]=0;
            }else M[ite->first]--;
        }
    }

    int max = 0;
    for(ite=M.begin();ite!=M.end();ite++){
        if(ite->second>max){
            max = ite->second;
        }
    }
    cout << max << endl;
    return 0;
}