class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        int n = s.size();
        long long totalCost = 0; 
        for (int i = 0; i < n; ++i) {
            int start = s[i] - 'a';  
            int target = t[i] - 'a'; 
            int clockwiseShifts = (target - start + 26) % 26;
            long long clockwiseCost = 0;
            for (int j = 0; j < clockwiseShifts; ++j) {
                clockwiseCost += nextCost[(start + j) % 26];
            }
            int counterClockwiseShifts = (start - target + 26) % 26;
            long long counterClockwiseCost = 0;
            for (int j = 0; j < counterClockwiseShifts; ++j) {
                counterClockwiseCost += previousCost[(start - j + 26) % 26];
            }
            totalCost += min(clockwiseCost, counterClockwiseCost);
        }
        return totalCost;
    }
};
