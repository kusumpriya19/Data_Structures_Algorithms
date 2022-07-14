// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> ratio(n);
        for(int i=0; i<n; i++){
            ratio[i].first = arr[i].value / (double)arr[i].weight;
            ratio[i].second = i;
        }
        sort(ratio.begin(), ratio.end());
        double ans = 0;
        for(int i=n-1; i>=0; i--){
            if(W==0)
            break;
            else{
                if(arr[ratio[i].second].weight <= W){
                    ans += arr[ratio[i].second].value;
                    W = W- arr[ratio[i].second].weight;
                }
                else{
                    ans += (arr[ratio[i].second].value*W / (double)arr[ratio[i].second].weight);
                    W=0;
                }
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends