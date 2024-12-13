class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        vector<bool> vis(nums.size(), false);
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            int value = v[i].first;
            int index = v[i].second;

            if (!vis[index]) {
                ans += value; 
                vis[index] = true;
                if (index + 1 < nums.size()) vis[index + 1] = true;
                if (index - 1 >= 0) vis[index - 1] = true; 
            }
        }

        return ans;
    }
};