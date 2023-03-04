class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        int mini = -1;
        int maxi = -1;
        int start = 0;
        
        long long ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>maxk || nums[i]<mink){
                start = i+1;
                mini = i;
                maxi = i;
                continue;
            }
            if(nums[i]==mink){
                mini = i;
            }
            if(nums[i]==maxk)
                maxi = i;
            ans += (i-start+1) - (i- (min(maxi,mini)+1) + 1);
        }
        return ans;
    }
};