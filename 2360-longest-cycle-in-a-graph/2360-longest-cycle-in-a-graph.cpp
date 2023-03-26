class Solution {
public:
    
    void dfs(vector<int> &vis, vector<int> &edges, int &ans, int i, int &count){
        vis[i] = count;
        count++;
        if(edges[i] == -1 || vis[edges[i]] == -3){
            vis[i] = -1;
            return;
        }
        else if(vis[edges[i]] != -1)
            ans = max(ans, count-vis[edges[i]]);
        else dfs(vis,edges,ans,edges[i], count);
        vis[i] = -1;
    }
    
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), ans = -1, count;
        vector<int> vis(n, -1);
        for(int i=0; i<n; i++){
            if(vis[i] == -1){
                count = 1;
                dfs(vis,edges,ans,i,count);
                vis[i] = -3;
            }
        }
        return ans;
    }
};