class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        int left = nums[0][0], right = nums[0][0];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_heap;
        for (int i = 0; i < k; ++i) {
            left = min(left, nums[i][0]);
            right = max(right, nums[i][0]);
            min_heap.push({nums[i][0], i, 0});
        }
        vector<int> res = {left, right};

        while (true) {
            auto current = min_heap.top();
            min_heap.pop();
            int n = current[0], i = current[1], idx = current[2];
            idx += 1;
            if (idx == nums[i].size()) {
                return res;
            }
            int next_val = nums[i][idx];
            min_heap.push({next_val, i, idx});
            right = max(right, next_val);
            left = min_heap.top()[0];
            if (right - left < res[1] - res[0]) {
                res = {left, right};
            }
        }
        return res;
    }
};
