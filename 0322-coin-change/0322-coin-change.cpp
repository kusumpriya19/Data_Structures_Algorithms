class Solution {
public:
    
    int jaadu(int ind, int t, vector<int> &num, vector<vector<int>> &dp){
    if(ind==0){
        if(t%num[0] == 0)
        return t/num[0];
        return 1e9;
    }
    if(dp[ind][t] != -1)
    return dp[ind][t];
    int nottake = 0+jaadu(ind-1,t,num,dp);
    int take = INT_MAX;
    if(num[ind] <= t){
        take = 1+jaadu(ind,t-num[ind],num,dp);
    }
    return dp[ind][t] = min(nottake,take);
}
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1,-1));
        
        int ans = jaadu(n-1,amount,coins,dp);
        if(ans==1e9)
            return -1;
        return ans;
    }
};