class Solution {
public:
    int helper(int n, vector<int> &stairs) {
        if (n < 0) return 0;
        if (n == 0) return 1;

        if (stairs[n] != -1)
            return stairs[n];

        return stairs[n] = helper(n - 1, stairs) + helper(n - 2, stairs);
    }

    int climbStairs(int n) {
        vector<int> stairs(n + 1, -1);
        return helper(n, stairs);
    }
};