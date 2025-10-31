class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        vector<int> last(256, -1);
        int start = 0;   
        int maxLen = 0;  

        for (int i = 0; i < (int)s.size(); ++i) {
            unsigned char c = s[i]; 
            if (last[c] >= start) {
                start = last[c] + 1;
            }
            last[c] = i;
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};