class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        for (auto &it : freq) {
            bucket[it.second].push_back(it.first);
        }

        int count = 0;
        vector<int> ans;

        for (int i = n; i >= 0; i--) {
            for (int j = 0; j < bucket[i].size(); j++) {
                ans.push_back(bucket[i][j]);
                count++;
                if (count >= k)
                    return ans;
            }
        }

        return ans;
    }
};