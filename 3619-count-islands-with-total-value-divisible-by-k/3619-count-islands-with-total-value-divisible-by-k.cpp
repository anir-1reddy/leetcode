class Solution {
public:
    int m, n;

    vector<vector<int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    long long dfs(int i, int j, vector<vector<int>>& grid) {
        long long sum = 0;
        stack<pair<int, int>> st;

        st.push({i, j});
        sum += grid[i][j];
        grid[i][j] = 0;

        while (!st.empty()) {
            auto [x, y] = st.top();
            st.pop();

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < m &&
                    ny >= 0 && ny < n &&
                    grid[nx][ny] > 0) {
                    sum += grid[nx][ny];
                    grid[nx][ny] = 0;
                    st.push({nx, ny});
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty())
            return 0;

        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    long long sum = dfs(i, j, grid);

                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};