#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int N;
    cin >> N;
    set<int> S;
    for(int i=0;i<N;i++){
        int t;
        cin >> t;
        S.insert(t);
    }
    cout << S.size() << endl;
    return 0;
}