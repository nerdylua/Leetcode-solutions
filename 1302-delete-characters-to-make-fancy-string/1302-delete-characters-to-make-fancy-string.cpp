class Solution {
public:
     string makeFancyString(const  string& s) {
        int n = s.length();
         string result;
        
        if (n < 3) {
            return s;
        } else {
            result += s[0];
            result += s[1];
            
            for (int i = 2; i < n; i++) {
                if (s[i] != s[i - 1] || s[i] != s[i - 2]) {
                    result += s[i];
                }
            }
            
            return result;
        }
    }
};
