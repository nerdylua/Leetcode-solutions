class Solution {
public:
    long long minimumSteps(string s) {
        long long counter = 0;
        int black = 0;
        for (const char ch : s){
            if (ch == '1')
            ++black;
            else
            counter += black; 
        }
        return counter;
    }
};