class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        int cnt = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int fcx = -1, lcx = -1;
            for (int i = 0; i < n; i++) {
                if (s[i] == c) {
                    if (fcx == -1) fcx = i;
                    lcx = i;
                }
            }
            if (fcx != -1 && lcx != -1 && lcx - fcx > 1) {
                set<char> ct;
                for (int j = fcx + 1; j < lcx; j++) {
                    ct.insert(s[j]);
                }

                cnt += ct.size();
            }
        }
        return cnt;
    }
};