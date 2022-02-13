// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        sort(arr,arr+n);
        int *ans = new int[2];
        int s=arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] == arr[i-1]){
                ans[0]=arr[i];

            }
            
        }
        if(arr[0] != 1){
            ans[1]=1;
        }
        else if(arr[n-1] != n){
            ans[1]=n;
        }
        else{
            for(int i=1; i<n; i++){
                if(arr[i]-arr[i-1] == 2)
                ans[1] = arr[i-1]+1;
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends