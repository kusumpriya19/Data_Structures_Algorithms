// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
const int mod = 1e9+7;
    int countFriendsPairings(int n) 
    { 
        // code here // tc - o(n) sc - o(1)
        long long a = 1, b=2, c=0;
        if(n<=2)
        return n;
        
        for(int i=3; i<n+1; i++){
            c = (b+(i-1)*a)%mod;
            a=b;
            b=c;
        }
        return c%mod;
       
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends