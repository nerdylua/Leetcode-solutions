class Solution {
public:
    int minLength(string s) {
        stack<char> k;
        for(char chr : s) {
            if(k.empty()) 
                k.push(chr);
            else {
                char Top = k.top();
                if((Top == 'A' && chr == 'B') || (Top == 'C' && chr == 'D')) {
                    k.pop();
                } else {
                    k.push(chr);
                }
            }
        }
        return k.size();
    }
};