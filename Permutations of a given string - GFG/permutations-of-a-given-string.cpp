// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void permutation(int index, set<string> &ans, string S){
	    if(index == S.size()){
	        ans.insert(S);
	        return;
	    }
	    
	    for(int i=index; i<S.size(); i++){
	        swap(S[index], S[i]);
	        permutation(index+1, ans, S);
	        swap(S[index],S[i]);
	    }
	}
	
		vector<string>find_permutation(string S)
		{
		    set<string> ans;
		    permutation(0,ans,S);
		    vector<string> res = {ans.begin(), ans.end()};
		    return res;
		}
		
		
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends