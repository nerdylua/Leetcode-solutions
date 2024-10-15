class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long int res = 0;
        priority_queue<int> max_heap(nums.begin(), nums.end());
        
        while (k--) {
            int n = max_heap.top();
            max_heap.pop();
            res += n;
            max_heap.push(ceil(n / 3.0));
        }
        return res;
    }
};

