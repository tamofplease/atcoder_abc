// "Copyright 2022 tam"
#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)
#define ALL(v) v.begin(), v.end()
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

#define ll int64_t

using P = pair<int, int>;

const int MOD = 1000000007;
// [a, b, c]  [a,b,c]
// [d, e, f]  [d,e,f]
// [g, h, i]  [g,h,i]
class Mat3 {
   public:
    vector<vector<ll>> mat;

    Mat3(vector<vector<ll>> v) { mat = v; }

    Mat3 operator*(Mat3 other) {
        return Mat3({
            {
                mat[0][0] * other.mat[0][0] + mat[0][1] * other.mat[1][0] + mat[0][2] * other.mat[2][0],
                mat[0][0] * other.mat[0][1] + mat[0][1] * other.mat[1][1] + mat[0][2] * other.mat[2][1],
                mat[0][0] * other.mat[0][2] + mat[0][1] * other.mat[1][2] + mat[0][2] * other.mat[2][2],
            },
            {
                mat[1][0] * other.mat[0][0] + mat[1][1] * other.mat[1][0] + mat[1][2] * other.mat[2][0],
                mat[1][0] * other.mat[0][1] + mat[1][1] * other.mat[1][1] + mat[1][2] * other.mat[2][1],
                mat[1][0] * other.mat[0][2] + mat[1][1] * other.mat[1][2] + mat[1][2] * other.mat[2][2],
            },
            {
                mat[2][0] * other.mat[0][0] + mat[2][1] * other.mat[1][0] + mat[2][2] * other.mat[2][0],
                mat[2][0] * other.mat[0][1] + mat[2][1] * other.mat[1][1] + mat[2][2] * other.mat[2][1],
                mat[2][0] * other.mat[0][2] + mat[2][1] * other.mat[1][2] + mat[2][2] * other.mat[2][2],
            },
        });
    }
};

vector<ll> mul(Mat3 a, vector<ll>& b) {
    return {
        a.mat[0][0] * b[0] + a.mat[0][1] * b[1] + a.mat[0][2] * b[2],
        a.mat[1][0] * b[0] + a.mat[1][1] * b[1] + a.mat[1][2] * b[2],
        a.mat[2][0] * b[0] + a.mat[2][1] * b[1] + a.mat[2][2] * b[2],
    };
}

// x = pで折り返し
Mat3 foldX(ll p) {
    return Mat3({{1, 0, p}, {0, 1, 0}, {0, 0, 1}}) * Mat3({{-1, 0, 0}, {0, 1, 0}, {0, 0, 1}}) *
           Mat3({{1, 0, -p}, {0, 1, 0}, {0, 0, 1}});
};

// y = pで折り返し
Mat3 foldY(ll p) {
    return Mat3({{1, 0, 0}, {0, 1, p}, {0, 0, 1}}) * Mat3({{1, 0, 0}, {0, -1, 0}, {0, 0, 1}}) *
           Mat3({{1, 0, 0}, {0, 1, -p}, {0, 0, 1}});
}

Mat3 rotateR = Mat3({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}});
Mat3 rotateL = Mat3({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}});

int main() {
    int n, m, q;
    cin >> n;
    vector<vector<ll>> points(n, vector<ll>(3, 1));
    vector<Mat3> v = {Mat3({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}})};
    rep(i, n) cin >> points[i][0] >> points[i][1];
    cin >> m;
    rep(i, m) {
        int t;
        cin >> t;
        if (t == 1) {
            v.push_back(rotateR);
        }
        if (t == 2) {
            v.push_back(rotateL);
        }
        if (t == 3) {
            ll x;
            cin >> x;
            v.push_back(foldX(x));
        }
        if (t == 4) {
            ll y;
            cin >> y;
            v.push_back(foldY(y));
        }
    }
    Rep(i, m) v[i] = v[i] * v[i - 1];
    cin >> q;
    rep(i, q) {
        int a, b;
        cin >> a >> b, b--;
        vector<ll> res = mul(v[a], points[b]);
        cout << res[0] << " " << res[1] << endl;
    }
    return 0;
}
