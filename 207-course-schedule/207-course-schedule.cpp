class Solution {
public:
    // directed graph where we need to find if we have a cycle or not
    // using bfs and indegrees we can find it
    // if indegree == 0 kisi ka bhi nahi hai that means it has a loop
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        
        for(int i=0; i<p.size(); i++){
            int u = p[i][0];
            int v = p[i][1];
            adj[v].push_back(u);
        }
        vector<int> indegree(n,0);
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        
        for(int i=0; i<n; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        if(q.empty()){
            return false;
        }
        int cnt = 0;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[x]){
                
                if(--indegree[it] == 0)
                    q.push(it);
            }
        }
        
        return cnt == n;
        
    }
};