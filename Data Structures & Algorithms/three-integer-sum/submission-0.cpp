class Solution {
public:
    vector<vector<int>> twoSum(int target, int idx, vector<int> &nums) {
        vector<vector<int>> ans;
        unordered_set<int> uset;

        for (int i = idx; i < nums.size(); i++) {
            if (uset.find(target - nums[i]) != uset.end()) {
                vector<int> p;
                p.push_back(target - nums[i]);
                p.push_back(nums[i]);
                ans.push_back(p);
                while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                    i++;
            }
            uset.insert(nums[i]);
        }

        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            vector<vector<int>> pairs = twoSum(-nums[i], i + 1, nums);

            for (int k = 0; k < pairs.size(); k++) {
                vector<int> triplet;
                triplet.push_back(nums[i]);
                triplet.push_back(pairs[k][0]);
                triplet.push_back(pairs[k][1]);
                ans.push_back(triplet);
            }
        }

        return ans;
    }
};