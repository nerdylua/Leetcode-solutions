class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if (nums[i]%2 == (nums[i-1])%2){
                prefix[i]++;
            }
        }
        int black = queries.size();
        vector<bool> ans(black, true); 
        for(int i = 0; i < black;++i){
            if(prefix[queries[i][0]] != prefix[queries[i][1]]){
                ans[i] = false;
            }
        }

        return ans; 
    }
};