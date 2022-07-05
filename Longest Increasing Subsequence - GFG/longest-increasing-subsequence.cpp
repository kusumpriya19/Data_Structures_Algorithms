// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int ind, int n, int a[], int prev, int dp[]){
        if(ind==n)
        return 0;
        if(dp[prev+1] != -1)
        return dp[prev+1];
        
        if(prev == -1 || a[ind]>a[prev]){
            int with = 1+solve(ind+1,n,a,ind,dp);
            
            int without = solve(ind+1,n,a,prev,dp);
            return dp[prev+1] = max(with,without);
        }
        else
        return dp[prev+1] = solve(ind+1,n,a,prev,dp);
    }
    
    int longestSubsequence(int n, int a[])
    {
        int dp[n+1];
        memset(dp,-1, sizeof dp);
        return solve(0,n,a,-1,dp);
        
       // your code here
       
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends