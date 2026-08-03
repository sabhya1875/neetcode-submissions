class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> seen(m, vector<bool>(n, false));
        vector<pair<int, int>> idx = {{-1,0},{0,-1},{1,0},{0,1}};

        int maxs = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (seen[i][j] || grid[i][j] == 0)
                    continue;

                seen[i][j] = true;
                int island = 1;

                queue<pair<int,int>> q;
                q.push({i,j});

                while (!q.empty()) {
                    auto curr = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ni = curr.first + idx[k].first;
                        int nj = curr.second + idx[k].second;

                        if (isValid(ni, nj, m, n) &&
                            !seen[ni][nj] &&
                            grid[ni][nj] == 1) {

                            seen[ni][nj] = true;
                            q.push({ni, nj});
                            island++;
                        }
                    }
                }

                maxs = max(maxs, island);
            }
        }

        return maxs;
    }
};