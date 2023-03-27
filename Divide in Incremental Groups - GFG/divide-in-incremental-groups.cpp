//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  int solve(int i, vector<int> &arr, int n, int k, int sum, vector<vector<vector<int>>> &dp){
      if(sum>n)
      return 0;
      if(k==0){
          if(sum==n)
          return dp[i][sum][k] = 1;
          else
          return dp[i][sum][k] = 0;
      }
      if(i==arr.size())
      return dp[i][sum][k] = 0;
      
      if(dp[i][sum][k] != -1)
      return dp[i][sum][k];
      
      return dp[i][sum][k] = solve(i,arr,n,k-1,sum+arr[i],dp) + solve(i+1,arr,n,k,sum,dp);
      
  }
  
    int countWaystoDivide(int n, int k) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (n+1, vector<int> (k+1, -1)));
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            arr[i] = i+1;
        }
        return solve(0,arr,n,k,0,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends