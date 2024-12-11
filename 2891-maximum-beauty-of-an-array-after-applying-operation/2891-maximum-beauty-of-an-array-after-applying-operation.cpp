class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort (nums.begin(), nums.end());
        int i = 0, j = 1;
        int cnt = 1, maxBeauty = 1;
        while (j < n) {
            if (nums[j] - nums[i] <= 2 * k) {
                j++;
                cnt++;
            } else {
                i++;
                cnt--;
            }
            maxBeauty = max (cnt, maxBeauty);
        }
        return maxBeauty;
    }
};