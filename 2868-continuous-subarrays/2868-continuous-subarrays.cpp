class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int, int>mp;
        int n = nums.size();
        int right = 1; 
        mp[nums[0]] = 1;  
        long long result = 0;
        for (int i = 0; i < n; i++) {
            while (right < n && (*mp.rbegin()).first - (*mp.begin()).first <= 2) {
                mp[nums[right]]++;
                right++;
            }
    
            result += (0LL + (right - i));     
            if ((*mp.rbegin()).first - (*mp.begin()).first > 2)
                result--;           
            mp[nums[i]]--;
            if (mp[nums[i]] == 0) {
                mp.erase(nums[i]);
            }
        }
        return result;
    }
};