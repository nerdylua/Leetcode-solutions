class Solution {
public:
    int romanToInt(const string &s) {
        static const unordered_map<char,int> val = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int n = s.size();
        int result = 0;
        for (int i = 0; i < n; ++i) {
            int cur = val.at(s[i]);
            if (i + 1 < n) {
                int next = val.at(s[i + 1]);
                if (cur < next) {
                    result -= cur;
                } else {
                    result += cur;
                }
            } else {
                result += cur;
            }
        }
        return result;
    }
};
