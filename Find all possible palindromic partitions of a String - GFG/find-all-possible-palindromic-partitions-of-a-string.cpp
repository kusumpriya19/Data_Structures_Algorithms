// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    
  
  public:
  
    
    void dfs(vector<vector<string>> &ans, int start, vector<string> path, int n, string S){
        if(start == n){
            ans.push_back(path);
            return;
        }
        
        for(int i=start; i<n; i++){
            if(isValid(S,start,i)){
                path.push_back(S.substr(start,i-start+1));
                
                dfs(ans,i+1,path,n,S);
                
                path.pop_back();
            }
            
        }
    }
    bool isValid(string s, int low, int high){
      while(high>low){
          if(s[low] != s[high])
          return false;
          
          low++;
          high--;
      }
      return true;
  }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> ans;
        int len = S.size();
        
        vector<string> str;
        
        dfs(ans,0,str,len,S);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends