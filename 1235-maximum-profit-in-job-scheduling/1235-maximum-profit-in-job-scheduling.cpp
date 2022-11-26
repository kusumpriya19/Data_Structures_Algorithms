class Solution {
public:
    struct x{
        int start;
        int end;
        int profit;
        
    };
    static int sortbyEndtime(x a, x b){
        return a.end < b.end;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int sz = startTime.size();
        int dp[sz];
        vector<x> v(sz);
        for(int i=0; i<sz; i++){
            v[i].start = startTime[i];
            v[i].end = endTime[i];
            v[i].profit = profit[i];
        }
        sort(v.begin(), v.end(), sortbyEndtime);
        for(int i=0; i<sz; i++){
            if(!i){
                dp[i] = v[i].profit;
                continue;
            }
            int f = 0;
            for(int j=i-1; j>=0; j--){
                if(v[j].end <= v[i].start){
                    f = dp[j];
                    break;
                }
            }
            dp[i] = max(dp[i-1], f + v[i].profit);
        }
        return dp[sz-1];
        
    }
};