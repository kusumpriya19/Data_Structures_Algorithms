// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[1000][1000];
    int solve(vector<vector<int>> &M,int x,int y,int n,int m){
       if(x<0 || x>=n){
           return 0;
       }
       if(y==m-1){
           return M[x][y];
       }
       if(dp[x][y]!=-1){
           return dp[x][y];
       }
       //cout<<x<<" "<<y<<endl;
       int right=M[x][y]+solve(M,x,y+1,n,m);
       int bottomRight=M[x][y]+solve(M,x+1,y+1,n,m);
       int topRight=M[x][y]+solve(M,x-1,y+1,n,m);
       dp[x][y]=max(right,max(topRight,bottomRight));
       return max(right,max(topRight,bottomRight));
   }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        
        for(int i=0;i<n+1;i++){
          for(int j=0;j<m+1;j++){
              dp[i][j]=-1;
          }
      }
      int mx=0;
      for(int i=0;i<n;i++){
         mx=max(mx,solve(M,i,0,n,m)) ;
      }
        return mx;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends