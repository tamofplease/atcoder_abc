#include <bits/stdc++.h>
using namespace std;
#define Rep(i,n) for(int i=1;i<=n;i++)
using Graph = vector<vector<int> >;
int N,X,Y;
const int MAXN = 2001;
int node[MAXN][MAXN];
int main(){
    cin >> N >>  X >> Y;
    map<int,int> comb;
    Rep(i,N)for(int j=i+1;j<=N;j++){
        int tmp = min(j-i, abs(j-Y)+abs(i-X)+1);
        comb[tmp]++;
    }
    Rep(i,N-1)cout << comb[i] << endl;
   return 0;
}