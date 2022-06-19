// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    //implement topo sort
	    
	    vector<int> adj[N];
	    int p = prerequisites.size();
	    
	    for(int i=0; i<p; i++){
	        int u = prerequisites[i].first;
	        int v = prerequisites[i].second;
	        
	        adj[v].push_back(u);
	        
	    }
	    vector<int> indegree(N,0);
	   for(int i=0; i<N; i++){
	       for(auto it: adj[i]){
	           indegree[it]++;
	       }
	   }
	   queue<int> q;
	   for(int i=0; i<N; i++){
	       if(indegree[i]==0)
	       q.push(i);
	   }
	   vector<int> topo;
	   
	   while(!q.empty()){
	       
	       int x = q.front();
	       q.pop();
	       topo.push_back(x);
	       
	       for(auto it: adj[x]){
	           indegree[it]--;
	           if(indegree[it]==0)
	           q.push(it);
	       }
	   }
	   if(topo.size() < N)
	   return false;
	   return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends