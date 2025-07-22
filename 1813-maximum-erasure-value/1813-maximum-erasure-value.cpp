class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
    unordered_map<int, int> lastSeen; 
    int maxScore = 0, currentScore = 0;
    int start = 0; 

    for (int end = 0; end < nums.size(); ++end) {
        int num = nums[end];
        if (lastSeen.find(num) != lastSeen.end() && lastSeen[num] >= start) {
            start = lastSeen[num] + 1;
        }
        currentScore = accumulate(nums.begin() + start, nums.begin() + end + 1, 0);
        lastSeen[num] = end;
        maxScore = max(maxScore, currentScore);
    }
    return maxScore;
    }
};