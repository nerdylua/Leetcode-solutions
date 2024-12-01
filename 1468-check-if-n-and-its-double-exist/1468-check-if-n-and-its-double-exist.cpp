class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> s;
        for (const auto v : arr) {
            if (!v && s.contains(v))
                return true;
            if (s.contains(v << 1) || (v % 2 == 0 && s.contains(v >> 1)))
                return true;
            s.insert(v);
        }
        return false;
    }
};