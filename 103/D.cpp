#include <iostream>
using namespace std;
#define MAX 100001
int N,M;
int a[MAX],b[MAX];
int main(){
    cin >> N >> M;
    pair<int,int> P[MAX];
    for(int i=0;i<M;i++){
        cin >> a[i] >> b[i];
        P[i].first = b[i];
        P[i].second = a[i];
    }
    sort(P,P+M);
    
}