#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int> > G(N+3);
    for(int i=2;i<N+1;i++){
        int a;
        cin >> a;
        G[a].push_back(i);
    }
    int a[21];
    for(int i=N;i>=1;i--){
        if(G[i].empty()){
            a[i] = 1;
            continue;
        }
        int min = 10000000;
        int max = 0;
        for(auto z:G[i]){
            if(a[z]>=max)max = a[z];
            if(a[z]<=min)min = a[z];
        }
        a[i] = max+min+1;
    }
    cout << a[1] << endl;
    return 0;
}