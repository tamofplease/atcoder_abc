#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define ll long long 
#define rep(i,n) for(ll i=0;i<n;i++)

ll A,B;
vector<int> Va;
vector<int> Vb;
ll dpa[20][2][2];
ll dpb[20][2][2];//dp[ケタ数][未満][４、９]
int main(){

    cin >> A >> B;
    string a = to_string(A-1);
    string b = to_string(B);
    ll la = a.length();
    ll lb = b.length();
    dpa[0][0][0] = 1;
    dpb[0][0][0] = 1;
    for(int i=0;i<la;i++){
        int D = a[i]-'0';
        for(ll j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(ll x=0;x<(j?10:D+1);x++){
                    dpa[i+1][j||x<D][k||x==4||x==9] += dpa[i][j][k];
                }   
            }
        }
    }

    for(int i=0;i<lb;i++){
        int D = b[i]-'0';
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                for(int x=0;x<(j?10:D+1);x++){
                    dpb[i+1][j||x<D][k||x==4||x==9] += dpb[i][j][k];
                }   
            }
        }
    }
    ll ans = dpa[la][1][1]+dpa[la][0][1];
    ll bns = dpb[lb][1][1]+dpb[lb][0][1];

    
    cout << bns-ans<< endl;
    return 0;
}



