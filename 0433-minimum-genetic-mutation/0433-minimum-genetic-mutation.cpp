class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st{bank.begin(), bank.end()}; //holds the bank
        
        if(!st.count(end)) // if end in not present in bank
            return -1;
        //start bfs by pushing start
        queue<string> q;
        q.push(start);
        int steps=0, s;
        string cur, t;
        
        while(!q.empty()){
            s=q.size();
            while(s--){
                cur = q.front();
                q.pop();
                if(cur==end)
                    return steps;
                st.erase(cur);
                for(int i=0; i<8; i++){
                    t = cur;
                    t[i]='A';
                    if(st.count(t))
                        q.push(t);
                    t[i]='C';
                    if(st.count(t))
                        q.push(t);
                    t[i]='G';
                    if(st.count(t))
                        q.push(t);
                    t[i]='T';
                    if(st.count(t))
                        q.push(t);
                }
            }
            steps++;
        }
        return -1;
    }
};