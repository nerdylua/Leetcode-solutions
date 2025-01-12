class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() & 1) return false; 
        for (int i = 0, bal = 0; i < s.size(); ++i) {
            if (locked[i] == '0' || s[i] == '(') ++bal; 
            else --bal; 
            if (bal < 0) return false; 
        }
        for (int i = s.size()-1, bal = 0; 0 <= i; --i) {
            if (locked[i] == '0' || s[i] == ')') ++bal; 
            else --bal; 
            if (bal < 0) return false; 
        }
        return true; 
    }
};