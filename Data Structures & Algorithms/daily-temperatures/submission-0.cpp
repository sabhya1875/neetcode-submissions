class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> nge;
        vector<int> ans(temperatures.size(), 0);

        for (int i = temperatures.size() - 1; i >= 0; i--) {

            while (!nge.empty() && nge.top().first <= temperatures[i]) {
                nge.pop();
            }

            if (nge.empty())
                ans[i] = 0;
            else
                ans[i] = nge.top().second - i;

            nge.push({temperatures[i], i});
        }

        return ans;
    }
};