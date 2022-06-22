// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    
    void solve(vector<vector<int>> &ans, int sum, int index, vector<int> &path, vector<int> &A){
        if(index==A.size()){
        if(sum == 0){
            ans.push_back(path);
            
        }
        return;
        }
        
        if(A[index] <= sum){
            
            path.push_back(A[index]);
            solve(ans,sum-A[index],index,path,A);
            
            path.pop_back();
            
            
        }
        
        solve(ans,sum,index+1,path,A);
        
        
    }
    
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        set<int> s(A.begin(), A.end());
        A.assign(s.begin(), s.end());
        
        vector<vector<int>> ans;
        vector<int> path;
        solve(ans,B,0,path,A);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends