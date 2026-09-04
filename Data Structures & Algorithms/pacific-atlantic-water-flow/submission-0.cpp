class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pac(rows,vector<bool>(cols,false));
        vector<vector<bool>> atl(rows,vector<bool>(cols,false));

        auto bfs = [&](queue<pair<int,int>>& q,vector<vector<bool>>& visited){
            int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            while(!q.empty()){
                auto [r, c] = q.front();q.pop();
                for(auto& d : dirs){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                    if(heights[nr][nc] < heights[r][c]) continue;
                    if(visited[nr][nc]) continue;
                    visited[nr][nc] = true;
                    q.push({nr,nc}); 
                }
            }
        };

        queue<pair<int,int>> pacQ,atlQ;

        for(int i = 0;i < rows;i++){
            pac[i][0] = true; pacQ.push({i,0});
            atl[i][cols - 1] = true; atlQ.push({i,cols - 1});
        }
        for(int j = 0;j < cols;j++){
            pac[0][j] = true; pacQ.push({0,j});
            atl[rows - 1][j] = true; atlQ.push({rows - 1,j});
        }

        bfs(pacQ,pac);
        bfs(atlQ,atl);

        vector<vector<int>> res;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < cols;j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
