class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        int n = (int) nums.size();
        int ans = 0;
        if (n < 2) return ans;
        bool done = false;
        for (int& num : nums) {
            pq.push(num);
        }
        while (pq.size() >= 2) {
            long long first = pq.top(); pq.pop();
            long long second = pq.top(); pq.pop();
            if (first >= k && second >= k) break;
            pq.push(min(first, second) * 2 + max(first, second));
            ans++;
        }
        return ans;
    }
};