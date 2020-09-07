#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long 
string A,B;
vector<int> Sa;
vector<int> Sb;
int dpa[20][2][2];//dp[桁][Aよりちいさい][[4or9含む]
int dpb[20][2][2];

signed main(){
    cin >> A >> B;
    for(auto a:A){
        Sa.push_back(a-'0');
    }
    for(auto b:B){
        Sb.push_back(b-'0');
    }
    dpa[0][0][0] = 0;
    for(int i=0;i<Sa.size();i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int x=0;x<=(j?9:Sa[i]);x++){
                    if(Sa[i]==4||Sa[i]==9){
                        dpa[i+1][j||x<Sa[i]][k||x==4||x==9] = dpa[i][j][k];
                    }
                }
            }
        }
    }
    //bについても同様


    return 0;
}



