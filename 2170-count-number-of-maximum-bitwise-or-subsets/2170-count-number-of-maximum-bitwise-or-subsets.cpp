class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for (int n : nums) {
            max_or |= n; 
        }

        int length = nums.size();
        int res = 0;

        for (int subset = 1; subset < (1 << length); ++subset) {  
            int cur_or = 0;
            for (int i = 0; i < length; ++i) {
                if (subset & (1 << i)) {  
                    cur_or |= nums[i];   
                }
            }
            if (cur_or == max_or) { 
                ++res; 
            }
        }
        return res;
    }
};
