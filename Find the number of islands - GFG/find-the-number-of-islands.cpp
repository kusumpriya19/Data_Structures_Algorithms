// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis , int i, int j, int n, int m){
        
        
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || grid[i][j]=='0' )
        return;
        
        vis[i][j] = 1;
        
        int dir[8][2] = {{0,1},{1,0},{1,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1}};
        
        for(int p=0; p<8; p++){
            int x = dir[p][0] + i;
            int y = dir[p][1] + j;
            
            dfs(grid,vis,x,y,n,m);
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && vis[i][j]==0){
                    dfs(grid,vis,i,j,n,m);
                    ans++;
                }
                
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends