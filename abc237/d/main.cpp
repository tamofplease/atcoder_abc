#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
#define ALL(v) v.begin(), v.end()
const ll MOD = 1000000007;

struct node {
    int val;
    struct node *next;
    struct node *prev;
    node() : val(0), next(nullptr), prev(nullptr) {}
    node(int x) : val(x), next(nullptr), prev(nullptr) {}
    node(int x, node *next, node *prev) : val(x), next(next), prev(prev) {}
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    struct node head = node();
    string s; cin >> s;
    int sl = s.length();
    Rep(i, sl) {
        char c = s[i-1];
        struct node new_node = node(i);
        if(c == 'L') {
            new_node.prev = head.prev;
            head.prev = &new_node;
            new_node.next = &head;
        } else {
            new_node.next = head.next;
            head->next = &new_node;
            new_node->prev = &head;
        }
        head = new_node;
        cout << head.val << endl;
        if(head.next != nullptr) {
            cout << head.next->val << endl;
        }
        if(head.prev != nullptr) {
            cout << (head.prev)->val << endl;
        }
    }
    // while(head.prev != nullptr) {
    //     head = *head.prev;
    //     cout << head.val << endl;
    // }
    // while(head.next != nullptr) {
    //     cout << head.val << " ";
    //     head = *head.next;
    // }
    cout << endl;
    return 0;
}
