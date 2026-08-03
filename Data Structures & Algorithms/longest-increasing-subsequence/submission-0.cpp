class Solution {
public:
    int helper(int current, int index, vector<int>& nums,
               vector<vector<int>>& dp) {

        if (index >= nums.size())
            return 0;

        int curr = current + 1001;

        if (dp[curr][index] != -1)
            return dp[curr][index];

        if (nums[index] > current) {
            return dp[curr][index] = max(
                1 + helper(nums[index], index + 1, nums, dp),
                helper(current, index + 1, nums, dp)
            );
        }

        return dp[curr][index] =
            helper(current, index + 1, nums, dp);
    }

    int lengthOfLIS(vector<int>& nums) {

        vector<vector<int>> dp(
            2002,
            vector<int>(nums.size(), -1)
        );

        return helper(-1001, 0, nums, dp);
    }
};