#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
#define MAXN 100001
typedef pair<int,int> P;
int main(){
    cin >> N;
    vector<P> VP(N);
    for(int i=0;i<N;i++){
        int A;
        cin >> A;
        VP[i] = P(A,i+1);
    }
    sort(VP.begin(),VP.end());
    for(int i=0;i<N;i++){
        cout << VP[i].second <<" ";
    }
    cout << endl;
    return 0;
}