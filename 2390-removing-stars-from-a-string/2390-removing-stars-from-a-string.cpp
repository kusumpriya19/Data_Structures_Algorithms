class Solution {
public:
    string removeStars(string s) {
        string ans = "";
        int cnt=0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='*')
                cnt++;
            else{
                if(cnt==0)
                    ans += s[i];
                else
                    cnt--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};