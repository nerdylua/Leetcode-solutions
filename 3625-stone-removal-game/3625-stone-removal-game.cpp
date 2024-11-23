class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool turns = true; 
        while (n > 0) {
            if (n >= stones) {
                n -= stones; 
                stones--; 
            } else {
                break;
            }
            turns = !turns; 
        }
        return !turns;
    }
};
