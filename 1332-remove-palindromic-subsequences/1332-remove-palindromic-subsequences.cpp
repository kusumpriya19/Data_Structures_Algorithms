class Solution {
public:
    int removePalindromeSub(string s) {
        bool check = true;
        for(int i=0; i<s.size(); i++){
            if(s[i] != s[s.size()-i-1]){
                check = false;
                break;
            }
                
        }
        if(check){
            return 1;
        }
        return 2;
        
        
    }
};