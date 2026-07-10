#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, M;
    cin >> N >> M;
 
    vector<string> grid(N);
    queue<pair<int, int>> q;
 
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
        for (int j = 0; j < M; ++j) {
            if (grid[i][j] != '#' && grid[i][j] != '.') {
                q.push({i, j});
            }
        }
    }
 
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
 
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
 
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
 
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (grid[nx][ny] != '.') continue;
 
            grid[nx][ny] = grid[x][y];
            q.push({nx, ny});
        }
    }
 
    for (const string& row : grid) {
        cout << row << '\n';
    }
 
    return 0;
}