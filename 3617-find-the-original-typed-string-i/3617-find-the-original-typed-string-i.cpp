class Solution {
public:
    int possibleStringCount(const string& word) {
        vector<int> t;
        char last = '\0';

        for (char c : word) {
            if (c != last) {
                t.push_back(1);
                last = c;
            } else {
                t.back() += 1;
            }
        }

        int sum = 0;
        for (int v : t) {
            if (v > 1) {
                sum += v - 1;
            }
        }
        
        return sum + 1;
    }
};
