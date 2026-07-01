class Solution {
public:
    int n;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    bool check(int val, vector<vector<int>>& dist) {
        if (dist[0][0] < val || dist[n - 1][n - 1] < val)
            return false;

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0, 0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    !vis[nr][nc] && dist[nr][nc] >= val) {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;

        // Multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur.first.first;
            int c = cur.first.second;
            int d = cur.second;

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    dist[nr][nc] == -1) {

                    dist[nr][nc] = d + 1;
                    q.push({{nr, nc}, d + 1});
                }
            }
        }

        int low = 0, high = 0;

        for (auto &row : dist) {
            for (int x : row)
                high = max(high, x);
        }

        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(mid, dist)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};