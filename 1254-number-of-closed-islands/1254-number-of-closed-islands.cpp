class Solution {
public:
    
    bool dfs(vector<vector<int>> &grid, int i, int j){
        if(i<0 || j<0 || i >= grid.size() || j>= grid[0].size()){
            return false;
        }
        if(grid[i][j] == 1)
            return true;
        
        grid[i][j] = 1;
        
        bool d1 = dfs(grid, i+1, j);
        bool d2 = dfs(grid, i, j+1);
        bool d3 = dfs(grid, i-1, j);
        bool d4 = dfs(grid, i, j-1);
        
        return d1 && d2 && d3 && d4;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    ans += dfs(grid,i,j) ? 1 : 0;
                }
            }
        }
        return ans;
    }
};