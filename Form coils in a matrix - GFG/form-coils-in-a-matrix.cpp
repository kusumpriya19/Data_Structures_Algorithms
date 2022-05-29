// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> formCoils(int n) {
        
        vector<vector<int>> m(4*n, vector<int>(4*n));
        int num = 1;
        for(int i=0; i<4*n; i++){
            for(int j=0; j<4*n; j++){
                m[i][j] = num++;
            }
        }
        int a = 0, b=0, c = 4*n, d = c-1;
        
        vector<int> ans1;
        while(c>a && d>b){
            for(int i=a; i<c; i++)
            ans1.insert(ans1.begin(), m[i][b]); // inserting the first column
            
            a++; b++;
            
            for(int j=b; j<d; j++)
            ans1.insert(ans1.begin(), m[c-1][j]); //inserting last row till second last element
            
            b++; c--;
            
            for(int i=c-1; i>=a; i--)
                ans1.insert(ans1.begin(), m[i][d-1]); // inserting second last column reverse
             
             c--; d--;
            for(int j=d-1; j>=b; j--)
            ans1.insert(ans1.begin(), m[a][j]);
            
            a++; d--;
            
        }
        
        vector<int> ans2;
        a = 4*n-1, b = a, c=0, d=1;
        
        while(c<a && d<b){
            for(int i=a; i>=c; i--)
            ans2.insert(ans2.begin(), m[i][b]); // inserting the first column
            
            a--; b--;
            
            for(int j=b; j>=d; j--)
            ans2.insert(ans2.begin(), m[c][j]); //inserting last row till second last element
            
            b--; c++;
            
            for(int i=c; i<=a; i++)
            ans2.insert(ans2.begin(), m[i][d]); // inserting second last column reverse
             
             c++; d++;
             
            for(int j=d; j<=b; j++)
            ans2.insert(ans2.begin(), m[a][j]);
            
            a--; d++;
            
        }
        return {ans2, ans1};
        
    
        
        
        // code here
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends