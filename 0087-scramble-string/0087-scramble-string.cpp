class Solution {
public:
     unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
        
        
        int len = s1.size();
        if(len==1)
            return false;
       
        string key = s1 + " "+ s2;
        if(mp.find(key) != mp.end())
            return mp[key];
        
        
        for(int i=1; i<len; i++){
            if(isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return mp[key]= true;
            if(isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return mp[key]= true;
        }
        return mp[key]=false;
    }
};