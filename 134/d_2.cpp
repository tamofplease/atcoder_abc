#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i=0; i<n; i++)

int main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n, 0);
  
  set<int> st;
  rep(i, n) cin >> a[i];

  for (int i = n; i > 0; --i) {
    int cnt = 0;
    for (int j = i + i; j <= n; j += i) {
      cnt += b[j - 1];
    }
    if (cnt % 2 != a[i-1]) {
      b[i-1] = 1;
      st.insert(i);
    }
  }

  cout << st.size() << endl;
    if (st.size()) {
      for (auto&& itr : st) {
      cout << itr << " ";
    }
  }
  

}