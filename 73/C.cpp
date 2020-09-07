#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int A[100001];
int main(){
    int N;
    cin >> N;
    rep(i,N)cin >> A[i];
    sort(A,A+N);
    int i=0;
    int ans = 0;
   while(i<N){
       int t = A[i];
       int count = 0;
       while(i<N && A[i]==t)i++,count++;
       ans += count%2;
   }
    cout << ans << endl;
    return 0;
}