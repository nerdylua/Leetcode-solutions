class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexedNums; 
        for (int i = 0; i < nums.size(); ++i)
            indexedNums.push_back({nums[i], i});
        sort(indexedNums.begin(), indexedNums.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });
        vector<pair<int, int>> chosen(indexedNums.begin(), indexedNums.begin() + k);
        sort(chosen.begin(), chosen.end(), [](auto& a, auto& b){
            return a.second < b.second;
        });
        vector<int> result;
        for (auto& p : chosen)
            result.push_back(p.first);
        return result;
    }
};
