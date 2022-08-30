// "Copyright 2022 tam"
#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define rRep(i, n) for (int i = n; i >= 1; i--)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;
// using mint = modint1000000007;
using mint = modint998244353;

const int MOD = 1000000007;

template <typename T, int FAC_MAX>
struct Comb {
   private:
    vector<T> fac, ifac;

   public:
    Comb() {
        fac.resize(FAC_MAX, 1);
        ifac.resize(FAC_MAX, 1);
        Rep(i, FAC_MAX - 1) fac[i] = fac[i - 1] * i;
        ifac[FAC_MAX - 1] = T(1) / fac[FAC_MAX - 1];
        rRep(i, FAC_MAX - 2) ifac[i] = ifac[i + 1] * T(i + 1);
    }
    T aPb(int a, int b) {
        if (b < 0 || a < b) return T(0);
        return fac[a] * ifac[a - b];
    }
    T aCb(int a, int b) {
        if (b < 0 || a < b) return T(0);
        return fac[a] * ifac[a - b] * ifac[b];
    }
    T nHk(int n, int k) {
        if (n == 0 && k == 0) return T(1);
        if (n <= 0 || k < 0) return 0;
        return aCb(n + k - 1, k);
    }
    T pairCombination(int n) {
        if (n % 2 == 1) return T(0);
        return fac[n] * ifac[n / 2] / (T(2) ^ (n / 2));
    }
};

// x,y座標型
typedef struct point {
    double x;
    double y;
} Point;

//弧度法の角度から度数法へ
double rad2deg(double rad) { return rad * (180 / M_PI); }

//角度計算関数
double angle(Point a, Point b, Point c) {
    int i;
    double ang;

    Point poly[3] = {a, b, c};
    // 2番目の点bを(0, 0)にし，両端点の値もそれに揃える
    double tmpx = poly[1].x;
    double tmpy = poly[1].y;
    for (i = 0; i < 3; ++i) {
        poly[i].x -= tmpx;
        poly[i].y -= tmpy;
    }

    //ベクトルの内積よりcosθを計算し，角度(0 < θ < 180)を算出
    ang = acos((poly[0].x * poly[2].x + poly[0].y * poly[2].y) /
               (sqrt(pow(poly[0].x, 2) + pow(poly[0].y, 2)) * sqrt(pow(poly[2].x, 2) + pow(poly[2].y, 2))));
    ang = rad2deg(ang);

    //符号付き面積を計算し，符号により実際の角度が180度以下か以上かを判定
    if (poly[2].x * poly[0].y - poly[0].x * poly[2].y < 0) {
        return 360 - ang;
    } else {
        return ang;
    }
}

int main() {
    vector<Point> v(4);
    for (auto& ref : v) cin >> ref.x >> ref.y;
    double a = angle(v[0], v[1], v[2]);
    double b = angle(v[1], v[2], v[3]);
    double c = angle(v[2], v[3], v[0]);
    double d = angle(v[3], v[0], v[1]);
    if (a >= 180 || b >= 180 || c >= 180 || d >= 180) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}
