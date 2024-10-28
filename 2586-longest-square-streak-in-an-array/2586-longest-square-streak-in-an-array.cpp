class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> ump;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int temp = sqrt(nums[i]);
            if(temp * temp == nums[i] && ump[temp])
            {
                ump[nums[i]] = ump[temp] + 1;
                res = max(res, ump[nums[i]]);
            }
            else
                ump[nums[i]] = 1;
        }
        if(res == 0)
            return -1;
        return res;
    }
};