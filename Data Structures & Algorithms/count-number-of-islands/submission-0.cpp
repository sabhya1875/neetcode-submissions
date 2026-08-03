class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> seen(m, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{-1,0}, {0,-1}, {1,0}, {0,1}};

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (seen[i][j] || grid[i][j] == '0')
                    continue;

                islands++;

                queue<pair<int, int>> q;
                q.push({i, j});
                seen[i][j] = true;

                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ni = curr.first + dir[k].first;
                        int nj = curr.second + dir[k].second;

                        if (isValid(ni, nj, m, n) &&
                            !seen[ni][nj] &&
                            grid[ni][nj] == '1') {

                            seen[ni][nj] = true;
                            q.push({ni, nj});
                        }
                    }
                }
            }
        }

        return islands;
    }
};