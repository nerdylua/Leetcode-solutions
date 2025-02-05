class Solution {
public:
    int cnt = 0; char a, b;
    bool areAlmostEqual(string s, string t) {
        for (int i = 0; i < s.size(); i++) cnt = s[i] != t[i] ? cnt == 0 ? (a = s[i], b = t[i], cnt + 1) : cnt == 1 ? (s[i] == b && t[i] == a ? cnt + 1 : 3) : 3 : cnt;
        return cnt == 0 || cnt == 2;
    }
};