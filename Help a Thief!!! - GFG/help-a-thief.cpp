// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxCoins(int A[], int B[], int T, int N) {
        // code here
        
        vector<pair<int,int>> vp;
        for(int i=0; i<N; i++){
            vp.push_back({B[i],A[i]});
        }
        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        int ans = 0;
        for(int i=0 ; i<N; i++){
           int curr = min(T, vp[i].second);
           
           ans += curr * vp[i].first;
           T -= curr;
           
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends