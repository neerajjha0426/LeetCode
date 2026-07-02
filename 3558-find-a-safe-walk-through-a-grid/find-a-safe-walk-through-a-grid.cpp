class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> path(m, vector<int>(n, -1));

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        queue<pair<pair<int, int>, int>> q;

        int startHealth = health - grid[0][0];
        if (startHealth <= 0) return false;

        q.push({{0, 0}, startHealth});
        path[0][0] = startHealth;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int h = curr.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newHealth = h - grid[nr][nc];

                    if (newHealth > 0 && newHealth > path[nr][nc]) {
                        path[nr][nc] = newHealth;
                        q.push({{nr, nc}, newHealth});
                    }
                }
            }
        }

        return path[m - 1][n - 1] > 0;
    }
};