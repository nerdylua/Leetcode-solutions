class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int res = 0;
        for (int i : derived) {
            res = res ^ i;
        }
        if (!res)
            return true;
        return false;
    }
};