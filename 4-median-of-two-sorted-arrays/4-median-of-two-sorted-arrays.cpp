class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        int comb_len = len1+len2;
        vector<int> comb;
        for(int i=0; i<nums1.size(); i++){
            comb.push_back(nums1[i]);
        }
        for(int j=0; j<nums2.size(); j++){
            comb.push_back(nums2[j]);
        }
        sort(comb.begin(), comb.end());
        int a = comb_len/2;
        if(comb_len%2 == 0){
            
            double ans = comb[a]+comb[a-1];
            ans = ans/2;
            return ans;
        }
        else{
            double ans = comb[a];
            return ans;
        }
        return 0;
    }
};