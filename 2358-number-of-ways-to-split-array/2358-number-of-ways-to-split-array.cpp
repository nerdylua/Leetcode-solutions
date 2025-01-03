class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0;
        long long leftSum = 0; 
        int ans = 0;
        for (int num : nums) {
            totalSum += num;
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            leftSum += nums[i]; 
            long long rightSum = totalSum - leftSum; 
            if (leftSum >= rightSum) {
                ans++; 
            }
        }
        return ans;
    }
};