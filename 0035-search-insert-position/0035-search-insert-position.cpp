class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = lower_bound(nums.begin(), nums.end(),target)-nums.begin();
        return lo;
    }
};