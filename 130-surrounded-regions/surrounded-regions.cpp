class Solution {
    bool dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j, int n, int m, vector<pair<int, int>>& region) {
        vis[i][j] = 1;
        region.push_back({i, j});

        bool isOnBorder = (i == 0 || i == n-1 || j == 0 || j == m-1);
        
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        for(int x = 0; x < 4; x++) {
            int ni = i + dx[x];
            int nj = j + dy[x];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && board[ni][nj] == 'O') {
                if(dfs(board, vis, ni, nj, n, m, region)) {
                    isOnBorder = true;
                }
            }
        }

        return isOnBorder;
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    vector<pair<int, int>> region;
                    bool touchesBorder = dfs(board, vis, i, j, n, m, region);

                    if(!touchesBorder) {
                        for(auto& p : region) {
                            board[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};
