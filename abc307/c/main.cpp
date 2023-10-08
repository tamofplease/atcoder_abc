#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
int main(void) {
    string a[3][10];
    char tmp[10][11];
    int h[3], w[3];
    bool flag;
    for (int k = 0; k < 3; k++) {
        cin >> h[k] >> w[k];
        for (int i = 0; i < h[k]; i++) cin >> a[k][i];
    }
    for (int dh0 = -h[0] + 1; dh0 < h[2]; dh0++) {
        for (int dw0 = -w[0] + 1; dw0 < w[2]; dw0++) {
            for (int dh1 = -h[1] + 1; dh1 < h[2]; dh1++) {
                for (int dw1 = -w[1] + 1; dw1 < w[2]; dw1++) {
                    for (int i = 0; i < h[2]; i++)
                        for (int j = 0; j < w[2]; j++) tmp[i][j] = '.';
                    flag = true;
                    for (int i = 0; i < h[0]; i++) {
                        for (int j = 0; j < w[0]; j++) {
                            if (a[0][i][j] == '#') {
                                if (i + dh0 < 0) flag = false;
                                if (i + dh0 >= h[2]) flag = false;
                                if (j + dw0 < 0) flag = false;
                                if (j + dw0 >= w[2]) flag = false;
                                if (flag) tmp[i + dh0][j + dw0] = '#';
                            }
                        }
                    }
                    for (int i = 0; i < h[1]; i++) {
                        for (int j = 0; j < w[1]; j++) {
                            if (a[1][i][j] == '#') {
                                if (i + dh1 < 0) flag = false;
                                if (i + dh1 >= h[2]) flag = false;
                                if (j + dw1 < 0) flag = false;
                                if (j + dw1 >= w[2]) flag = false;
                                if (flag) tmp[i + dh1][j + dw1] = '#';
                            }
                        }
                    }
                    for (int i = 0; i < h[2]; i++) {
                        for (int j = 0; j < w[2]; j++) {
                            if (a[2][i][j] != tmp[i][j]) flag = false;
                        }
                    }
                    if (flag) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
