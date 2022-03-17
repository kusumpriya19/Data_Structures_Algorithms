// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

#define ll long long int
const ll mod = 1e9+7;

class Solution
{
  public:
    int kvowelwords(int N, int K) {
       vector<vector<ll>> dp(N+1,vector<ll>(K+1,1));
       for(int i=1; i<=N; i++){
           for(int j=0; j<=K; j++){
               if(j==0)
               dp[i][j] = (21*dp[i-1][K])%mod;
               else
               dp[i][j] = (5*dp[i-1][j-1]%mod + 21*dp[i-1][K]%mod)%mod;
           }
       }
       return dp[N][K];
       
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends