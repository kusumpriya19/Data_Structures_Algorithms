class Solution {
public:
    bool checkIfPangram(string sen) {
        
        sort(sen.begin(), sen.end());
        set<char> s;
        for(int i=0; i<sen.size(); i++){
            s.insert(sen[i]);
        }
        if(s.size() == 26)
            return true;
        return false;
        
    }
};