#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int R,C,K,N;
#define MAXR 100001
#define MAXN 100001
int Ra[MAXN],Ca[MAXN];

int main(){
    
    cin >> R >> C >> K;
    vector<vector<int> > V(R,vector<int>(C,0));
    cin >> N;
    fill(Ra,Ra+R,0);
    fill(Ca,Ca+C,0);
    for(int i=0;i<N;i++){
        int r,c;
        cin >> r >> c;
        V[r][c] = 1;
        Ra[r]++;
        Ca[c]++;
    }
    ll countc[MAXR];
    fill(countc,countc+C,0);
    ll countr[MAXR];
    fill(countr,countr+R,0);
    for(int i=0;i<N;i++){
        countr[Ra[i]]++;
        countc[Ca[i]]++;
    }
    for(int i=0;i<=K;i++){
        
    }


    return 0;
}