class Solution {
public:
    int helper(int n,vector<int> &nums, vector<int> &dp){
        if (n>=nums.size()) return 0;
        if (dp[n]!=-1) return dp[n];
        return dp[n]=max(nums[n]+helper(n+2,nums,dp),helper(n+1,nums,dp));
        }


    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> nums2(nums.begin(), nums.end()-1);
        vector<int> dp(n+1,-1);
        vector<int> dp2(n,-1);
        return max(helper(1,nums,dp),nums[0]+helper(2,nums2,dp2));
    }
};
