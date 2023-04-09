class Solution {
public:
    
    int dfs(string &colors,vector<int>adj[],int ind,vector<int>&vis,vector<vector<int>>&v){
        if(!vis[ind]){
            vis[ind] = 1;
            for(auto it : adj[ind]){
                if(dfs(colors,adj,it,vis,v) == INT_MAX) {
                    return INT_MAX;
                }
                for(auto i=0;i<26;i++){
                    v[ind][i] = max(v[ind][i],v[it][i]);
                }
            }
            ++v[ind][colors[ind]-'a'];
            vis[ind] = 2;
        }
        return vis[ind] == 2 ? v[ind][colors[ind]-'a'] : INT_MAX;
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();

        vector<vector<int>>v(n,vector<int>(26,0));
        vector<int>adj[n];

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }

        int ans = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n && ans!=INT_MAX;i++){
            ans = max(ans,dfs(colors,adj,i,vis,v));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};