class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<short int, char>, vector<pair<short int, char>>, greater<pair<short int, char>>> numsQueue;
        char numsLen = nums.size();
        for (char i = 0; i < numsLen; ++i) {
            numsQueue.push({nums[i], i});
        }
        while (k > 0) {
            auto lowestElement = numsQueue.top();
            numsQueue.pop();
            nums[lowestElement.second] *= multiplier;
            numsQueue.push({nums[lowestElement.second], lowestElement.second});
            --k;
        }
        return nums;
    }
};