#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    int R, C;
    cin >> R >> C;

    vector<vector<char>> grid(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<char>> result = grid;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] >= '1' && grid[i][j] <= '9') {
                int power = grid[i][j] - '0';
                for (int x = i - power; x <= i + power; ++x) {
                    for (int y = j - power; y <= j + power; ++y) {
                        if (x >= 0 && x < R && y >= 0 && y < C && abs(x - i) + abs(y - j) <= power) {
                            result[x][y] = '.';
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << result[i][j];
        }
        cout << endl;
    }

    return 0;
}
