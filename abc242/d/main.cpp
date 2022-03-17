#include<bits/stdc++.h>
using namespace std;

vector<int> makeToggle(vector<int> row) {
    vector<int> newRow;
    for(int i : row) {
        if(i == 0) {
            newRow.push_back(1);
        } else {
            newRow.push_back(0);
        }
    }
    return newRow;
}

int solve (int N, int M, int K, vector<vector<int> > matrix) {
   // Type your code here
   map<vector<int>, int> m;
   for(vector<int> row : matrix) {
       m[row]++;
   }
   int ans = 0;
   for(const auto& p : m) {
        vector<int> k = p.first;
        int v = p.second;
        vector<int> toggle = makeToggle(k);
        int res = m[toggle];
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        int M;
        cin >> M;
        int K;
        cin >> K;
        vector<vector<int> > matrix(N, vector<int>(M));
        for (int i_matrix = 0; i_matrix < N; i_matrix++)
        {
        	for(int j_matrix = 0; j_matrix < M; j_matrix++)
        	{
        		cin >> matrix[i_matrix][j_matrix];
        	}
        }

        int out_;
        out_ = solve(N, M, K, matrix);
        cout << out_;
        cout << "\n";
    }
}