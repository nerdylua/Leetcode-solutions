class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (nums[j] < nums[i]) {
                    if (__builtin_popcount(nums[i]) != __builtin_popcount(nums[j])) {
                        return false;
                    }
                    swap(nums[i], nums[j]);
                }
            }
        }
        for (int k = 0; k < length - 1; k++) {
            if (nums[k] > nums[k + 1]) {
                return false;
            }
        }

        return true;
    }
};