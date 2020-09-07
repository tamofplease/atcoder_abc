#include <iostream>
#include <vector>
#include <wchar.h>
using namespace std;

#define MAXN 100000

#define rep(i,N) for(int i=0;i<N;i++)

int N;
int a[MAXN];
int b[MAXN];



int main(){
    cin >> N;
    vector<vector<int> > E(vector<int>(N),N);

    rep(i,N-1){
        cin >> a[i] >> b[i];
        E[a[i]].push_bash(b[i]);
        E[b[i]].push_bask(a[i]);
    }
    
Cellar/gcc/9.2.0/include/c++/9.2.0/x86_64-apple-darwin18/bits/stdc++.h

    return 0;
}

/usr/local/Cellar/gcc/9.2.0/include/c++/9.2.0/cassert:44:10: fatal error: assert.h: No such file or directory
   44 | #include <assert.h>