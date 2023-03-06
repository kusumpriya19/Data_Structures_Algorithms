class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> ans;
        int cnt = 1;
        int i=0; 
        while(i<arr.size()){
            if(arr[i]>cnt){
                ans.push_back(cnt);
                cnt++;
                
            }
            else if(arr[i]==cnt){
                cnt++;
                i++;
            }
            
        }
        if(ans.size()>=k)
        return ans[k-1];
        int aa = k;
        while(aa--){
            ans.push_back(cnt);
            cnt++;
        }
        return ans[k-1];
        
    }
};