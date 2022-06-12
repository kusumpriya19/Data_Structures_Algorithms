// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    vector<int> ans;
    int lb = lower_bound(arr,arr+n,x)-arr;
    int ub = upper_bound(arr,arr+n,x)-arr;
    if(arr[lb] != x){
        ans.push_back(-1);
    }
    if(arr[ub-1] != x){
        ans.push_back(-1);
    }
    if(arr[lb] == x){
    ans.push_back(lb);
   
    }
    if(arr[ub-1] == x){
         ans.push_back(ub-1);
    }
    // cout<<arr[ub-1];
    
    return ans;
    
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


  // } Driver Code Ends