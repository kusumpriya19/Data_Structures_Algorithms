class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int num = intervals[0][1];
        int num2 = intervals[0][0];
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int j=0;
        
        for(int i=1; i<intervals.size(); i++){
            vector<int> temp;
            
            int a = intervals[i][0];
            int b = intervals[i][1];
            if(ans[j][1] >= intervals[i][0])
                ans[j][1] = max(ans[j][1],intervals[i][1]);
            else{
                j++;
                ans.push_back(intervals[i]);
            }
                
           
             
        }
       
        return ans;
        
    }
};

// tc - o(nlogn) sc - o(n);
//sort function - o(nlogn) + o(n)