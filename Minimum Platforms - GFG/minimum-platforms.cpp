// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool cmp(vector<int>&a,vector<int>&b)
    {
     return a[0]<b[0];
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	// Your code here
    	vector<vector<int>> intervals;
    	
    	for(int i=0;i<n;i++)
    	{
            intervals.push_back({arr[i],dep[i]});    	    
    	}
    	sort(intervals.begin(),intervals.end(),cmp);
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        pq.push(intervals[0][1]);
        
        for(int i=1;i<intervals.size();i++)
        {
            //  hamara maksad ye hai bass ki intervals[i][0] ko heap ke minimum end time se compare krna 
           // heap ka min end time uske top pe paya jaata hai 
            
            
            if(intervals[i][0]<=pq.top())
                pq.push(intervals[i][1]);
            
            else
            {
                pq.pop();
                pq.push(intervals[i][1]);
            }
            
        }
        return pq.size();
    	
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends