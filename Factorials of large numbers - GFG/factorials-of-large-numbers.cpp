// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int> ans;
        ans.push_back(1);
        for(int j=2; j<=N; j++){
            
            int carry = 0;
            for(int i=0; i<ans.size(); i++){
                int value = ans[i]*j+carry;
                ans[i] = value%10;
                carry = value/10;
            }
            while(carry != 0){
                ans.push_back(carry%10);
                carry /= 10;
            }
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// tc - o(n2)
// sc - o(n)

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends