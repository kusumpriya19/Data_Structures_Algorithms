class Solution {
public:
    int search(vector<int>& nums, int target) {
        bool check = false;
        for(int i=0; i<nums.size(); i++){
            if(target==nums[i])
                check=true;
        }
        if(check==false)
            return -1;
        int ind = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        return ind;
    }
};