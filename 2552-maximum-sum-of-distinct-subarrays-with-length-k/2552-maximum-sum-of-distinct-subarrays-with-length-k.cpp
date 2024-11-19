#define ll long long
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int freq[100001] = {0};
        int i = 0, j = 0, repeat = 0;
        ll sum = 0, maxsum = 0;
        while(j < n){
            sum += nums[j];
            if(++freq[nums[j]] == 2) ++repeat;
            while(i <= j && j-i+1 > k){
                sum -= nums[i];
                if(--freq[nums[i]]==1) --repeat;
                i++;
            }
            if(j-i+1 == k && !repeat){
                maxsum = max(maxsum, sum);
            }
            j++;
        }
        return maxsum;
    }
};