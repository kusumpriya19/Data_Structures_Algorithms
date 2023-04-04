class Solution {
public:
    int partitionString(string s) {
        unordered_set<int> us;
        
        int cnt=1;
        for(int i=0; i<s.size(); i++){
            if(us.find(s[i]) != us.end()){
                cnt++;
                us.clear();
            }
            us.insert(s[i]);
        }
        return cnt;
        
    }
};