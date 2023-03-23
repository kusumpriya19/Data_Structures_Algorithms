class Solution {
public:
    
    void dfs(vector<vector<int>> &adj, vector<int> &vis, int i){
        vis[i] = true;
        for(int it: adj[i]){
            if(!vis[it])
                dfs(adj,vis,it);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& conn) {
        if(conn.size()<n-1)
            return -1;
        vector<vector<int>> adj(n+1);
        
        int cc=0;
        for(auto it: conn){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n+1, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj,vis,i);
                cc++;
            }
        }
        return cc-1;
        
        
    }
};