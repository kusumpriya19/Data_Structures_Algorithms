//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        vector<char> low,high;
        for(int i=0; i<n; i++){
            if(isupper(str[i])){
                high.push_back(str[i]);
            }
            else{
                low.push_back(str[i]);
            }
        }
        sort(high.begin(), high.end());
        sort(low.begin(), low.end());
        string ans="";
        int j=0, k=0;
        for(int i=0; i<n; i++){
            if(isupper(str[i])){
                ans += high[j];
                j++;
            }
            else{
                ans += low[k];
                k++;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends