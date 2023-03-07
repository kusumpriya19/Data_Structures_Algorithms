class Solution {
public:
    
    long long int check(vector<int> &arr, long long mid){
        long long ans = 0;
        for(int i=0; i<arr.size(); i++){
            ans += mid/arr[i];
        }
        return ans;
    }
    
    long long minimumTime(vector<int>& arr, int tat) {
        long long int low = 1, high = 1e14, ans = 0;
        
        while(low < high){
            long long mid = low + (high-low)/2;
            if(check(arr,mid)>=tat){
                high = mid;
            }
            else
                low = mid+1;
        }
        return low;
    }
};