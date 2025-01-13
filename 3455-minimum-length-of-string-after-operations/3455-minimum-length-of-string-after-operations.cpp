class Solution {
public:
    int minimumLength(string s) {
        int len = s.length(); 
        vector<int> f(26, 0);  

        for (char c : s) {
            int curr = c - 'a';  
            f[curr]++;  
            if (f[curr] == 3) {
                f[curr] -= 2;  
                len -= 2;  
            }
        }

        return len;  
    }
};