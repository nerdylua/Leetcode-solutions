class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i = 0, result = 0;
        int n = nums.size();
        for (int j = 0; j < n; ++j) {
            if (j - i + 1 == 3) { 
                if ((nums[i] + nums[j]) * 2 == nums[i + 1]) {
                    ++result; 
                }
                ++i; 
            }
        }
        return result;
    }
};
