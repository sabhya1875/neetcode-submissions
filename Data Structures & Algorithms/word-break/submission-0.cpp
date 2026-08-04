class Solution {
public:
    vector<int> dp;

    bool helper(int index, string &s, set<string> &dict) {
        if (index == s.size())
            return true;

        if (dp[index] != -1)
            return dp[index];

        string temp;

        for (int j = index; j < s.size(); j++) {
            temp += s[j];

            if (dict.find(temp) != dict.end()) {
                if (helper(j + 1, s, dict))
                    return dp[index] = true;
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size(), -1);

        set<string> dict(wordDict.begin(), wordDict.end());

        return helper(0, s, dict);
    }
};