class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> tails;
        int len=0;
        for(int x : nums){

            auto it = lower_bound(tails.begin(), tails.end(), x);

            if(it == tails.end()){
                tails.push_back(x);
                len++;
            }
            else
                *it = x;
        }

        return len;
    }
};