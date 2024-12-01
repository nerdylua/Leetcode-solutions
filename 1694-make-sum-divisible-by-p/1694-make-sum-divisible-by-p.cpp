class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }
        int remainder = totalSum % p;
        if (remainder == 0) {
            return 0; 
        }
        unordered_map<int, int> prefixModIndex;
        prefixModIndex[0] = -1; 
        long long prefixSum = 0;
        int minLength = n;
        for (int i = 0; i < n; i++) {
            prefixSum = (prefixSum + nums[i]) % p;
            int targetMod = (prefixSum - remainder + p) % p;
            if (prefixModIndex.find(targetMod) != prefixModIndex.end()) {
                minLength = min(minLength, i - prefixModIndex[targetMod]);
            }
            prefixModIndex[prefixSum] = i;
        }
        return (minLength == n) ? -1 : minLength;
    }
};