#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;

    int N = S.size();
    vector<int> acc(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        acc[i + 1] = acc[i] ^ (1 << (S[i] - '0'));
    }

    map<int, long long> cnt;
    for (int i = 0; i <= N; i += 2) {
        cnt[acc[i]]++;
    }

    long long ans = 0;
    for (auto &p : cnt) {
        ans += p.second * (p.second - 1) / 2;
    }

    cnt.clear();
    for (int i = 1; i <= N; i += 2) {
        cnt[acc[i]]++;
    }

    for (auto &p : cnt) {
        ans += p.second * (p.second - 1) / 2;
    }

    cout << ans << endl;

    return 0;
}
