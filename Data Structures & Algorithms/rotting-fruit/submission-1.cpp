class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int> (m,-1));
        int fresh=0;
        for (int i =0; i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==2) {
                    q.push({i,j});
                    visited[i][j]=1;
                }
                if (grid[i][j]==1) fresh++;
            }
        }
        int time=-1;
        vector<pair<int,int>> d={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty()){
            time++;
            int size = q.size();
            while(size--){
                pair<int,int> temp = q.front();
                q.pop();
                for (int i =0; i<4;i++){
                    if (temp.first+d[i].first>=0 && temp.first+d[i].first<n &&
                        temp.second+d[i].second>=0 && temp.second+d[i].second<m &&
                        visited[temp.first+d[i].first][temp.second+d[i].second]==-1 
                    && grid[temp.first+d[i].first][temp.second+d[i].second]==1){
                        q.push({temp.first+d[i].first,temp.second+d[i].second});
                        visited[temp.first+d[i].first][temp.second+d[i].second]=1;
                        fresh--;
                    }
                }

            }
        }
        if (fresh!=0) return -1;
        else if (time==-1) return 0;
        else return time;
        
    }
};
