class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int count[256]= {0};
        
        int start=0, end =0, ans = 0;
        while(end <s.size()){
            count[s[end]]++;
            
            while(count[s[end]] > 1){
                count[s[start]]--;
                start++;
            }
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;
        
        
        
        
        
    }
};