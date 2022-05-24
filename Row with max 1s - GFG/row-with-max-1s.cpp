// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	  
	  int count = 0,ans=-1;    // Using Binary Search O(mLog(n))
   int i=0;
   for(;i<n;i++)
   {
       int l=0,h=m-1,mid;
       while(l<=h)
       {
           mid = l + (h-l)/2;
           
           if(arr[i][mid] < 1)
           l = mid+1;
           else
           h = mid-1;
 
       }
       
       if( count < m-l )
       {
            count = m-l;
            ans = i;
       }
       
   }
   return ans;
	    
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends