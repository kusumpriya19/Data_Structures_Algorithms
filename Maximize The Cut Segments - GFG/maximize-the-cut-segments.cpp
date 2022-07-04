// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        int dp[n+1];
        vector<int> v= {x,y,z};
        int max = 0, a;
        dp[0] = 0;
        for(int i=1; i<=n; i++){
            max = 0;
            for(int j=0; j<v.size(); j++){
                if(i-v[j] >= 0){
                    if(i-v[j] == 0 || dp[i-v[j]] != 0)
                    a = 1+dp[i-v[j]];
                    
                    else
                    a = 0+ dp[i-v[j]];
                }
                else{
                    a = 0;
                }
                if(a>max)
                max = a;
                
            }
            dp[i]=max;
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends