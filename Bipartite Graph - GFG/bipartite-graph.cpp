// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool check(int node, vector<int> adj[], int color[]){
        if(color[node]==-1)
        color[node]=1;
        
        for(auto it: adj[node]){
            if(color[it]==-1){
                color[it] = 1-color[node];
                if(!check(it,adj,color))
                return false;
            }
            else{
                if(color[it]==color[node])
                return false;
            }
        }
        return true;
    }


	bool isBipartite(int V, vector<int>adj[]){
	    int color[V];
	    memset(color,-1,sizeof color);
	    
	    for(int i=0; i<V; i++){
	        if(color[i]==-1){
	            if(!check(i,adj,color))
	            return false;
	        }
	    }
	    return true;
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends