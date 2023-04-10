class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        char x;
        if(s.size()==1)
            return false;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            if(st.empty()){
                return false;
            }
            if(s[i]==')'){
                x = st.top();
                st.pop();
                if(x == '[' || x == '{')
                    return false;
                
            }
            if(s[i]==']'){
                x = st.top();
                st.pop();
                if(x == '(' || x == '{')
                    return false;
                
            }
            if(s[i]=='}'){
                x = st.top();
                st.pop();
                if(x == '[' || x == '(')
                    return false;
                
            }
        }
        return(st.empty());
        
        
    }
};