class Solution {

private:
    void dfs(int row, int col,
             vector<vector<int>>& vis,
             vector<vector<int>>& board,
             int delrow[], int delcol[]) {

        vis[row][col] = 1;

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               board[nrow][ncol] == 1) {

                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& board) {

        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // First and last row
        for(int j = 0; j < m; j++) {

            if(board[0][j] == 1 && !vis[0][j]) {
                dfs(0, j, vis, board, delrow, delcol);
            }

            if(board[n - 1][j] == 1 && !vis[n - 1][j]) {
                dfs(n - 1, j, vis, board, delrow, delcol);
            }
        }

       
        for(int i = 0; i < n; i++) {

            if(board[i][0] == 1 && !vis[i][0]) {
                dfs(i, 0, vis, board, delrow, delcol);
            }

            if(board[i][m - 1] == 1 && !vis[i][m - 1]) {
                dfs(i, m - 1, vis, board, delrow, delcol);
            }
        }

        
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};