class Solution {
public:
    
    vector<int> adj[100001];
int vis[100001];
    int cmp=1;

    
    void dfs(int node){
        vis[node] = 1;
        for(auto child : adj[node]){
            if(!vis[child]){
                    dfs(child);
                cmp++;

            }
                
            
        }
        
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        
       
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int cc=0;
        vector<int> cpp;
        
        for(int i=0; i<n; i++){
            int child = 1;
            
            if(!vis[i]){
                cmp=1;
                dfs(i);
                
                cc++;
               cpp.push_back(cmp);
            }
                
        }
        if(cpp.size()==1)
            return 0;
        
        vector<int> suff;
        for(int i=0; i<cpp.size(); i++){
            suff.push_back(cpp[i]);
        }
        long long int ans = 0;
        reverse(suff.begin(), suff.end());
        
        for(int i=1; i<suff.size(); i++){
            suff[i] += suff[i-1];
        }
         reverse(suff.begin(), suff.end());
        for(int i=0; i<suff.size(); i++){
            long long pp = (suff[i]-cpp[i]);
            ans += cpp[i]*pp;
        }
        return ans;
        
    }
};