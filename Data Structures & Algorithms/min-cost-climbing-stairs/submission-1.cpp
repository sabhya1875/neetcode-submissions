class Solution {
public:

    int helper(int index,vector<int>&cost,vector<int> &dp){
        if (index>=cost.size()) return 0;
        if (dp[index]!=-1) return dp[index];
        return dp[index]=min(helper(index+1,cost,dp),helper(index+2,cost,dp))+cost[index];
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        return min(helper(0,cost,dp),helper(1,cost,dp));
    }
};
