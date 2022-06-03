// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        string exp = S;
         stack<int> st;
    for(int i=0; i<exp.size(); i++){
        if(exp[i] == '*' || exp[i] == '/' || exp[i] == '+' || exp[i] == '-'){
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();
            if(exp[i]=='*'){
                int ans = x*y;
                st.push(ans);
            }
            else if(exp[i]=='+'){
                int ans = x+y;
                st.push(ans);
                
            }
            else if(exp[i]=='/'){
                int ans = y/x;
                st.push(ans);
                
            }
            else if(exp[i]=='-'){
                int ans = y-x;
                st.push(ans);
                
            }
        }
        else{
            st.push(exp[i]-'0');
        }
    }
    int ans = st.top();
    return ans;
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends