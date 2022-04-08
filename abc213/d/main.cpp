#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
const ll MOD = 1000000007;

int main(){
    int n; cin >> n;
    vector<priority_queue<int, vector<int>, greater<int>>> node(n+1);
    vector<int> mem(n+1, -1); // 訪れていない場合は−１層でない場合は、どこからきたのかを記載する。
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        node[a].push(b);
        node[b].push(a);
    }

    queue<int> note;
    queue<int> been;
    note.push(1);
    mem[1] = 1;
    while(!note.empty()) {
        int currentNode = note.front(); note.pop();
        been.push(currentNode);
        while(node[currentNode].size() > 0 && mem[node[currentNode].top()] != -1) {
            node[currentNode].pop();
        }
        int nxt = node[currentNode].top();
        if(mem[nxt] == -1) {
            node[currentNode].pop();
            note.push(nxt);
            mem[nxt] = currentNode;
        } else {
            if(currentNode == 1){
                break;
            }
            note.push(mem[currentNode]);
        }
    }
    while(!been.empty()) {
        if(been.size() == 1) {
            cout << been.front() << endl;
        } else {
            cout << been.front() << " ";
        }
        been.pop();
    }
    return 0;
}
