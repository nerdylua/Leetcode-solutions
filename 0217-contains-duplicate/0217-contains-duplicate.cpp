class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> intset;
        for (auto element : nums)
        intset.insert(element);
        if(intset.size() == nums.size()) {
            return false;
        }
        return true;
    }
};