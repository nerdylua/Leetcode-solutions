class Solution {
public:
    long long dpCache[1 << 8][100];
    vector<int> taskStrength;
    int taskCount;
    int increment;
    long long calculateMinTime(int completedMask, int currentMultiplier) {
        if (completedMask == (1 << taskCount) - 1) 
            return 0; 
        if (dpCache[completedMask][currentMultiplier] != -1) 
            return dpCache[completedMask][currentMultiplier];
        
        long long minTime = LLONG_MAX;
        
        for (int i = 0; i < taskCount; ++i) {
            if (!(completedMask & (1 << i))) { 
                long long timeRequired = (taskStrength[i] + currentMultiplier - 1) / currentMultiplier; 
                int nextMultiplier = currentMultiplier + increment;
                long long totalTime = timeRequired + calculateMinTime(completedMask | (1 << i), nextMultiplier);
                minTime = min(minTime, totalTime);
            }
        }
        
        return dpCache[completedMask][currentMultiplier] = minTime;
    }
    int findMinimumTime(vector<int>& strengths, int incrementValue) {
        taskStrength = strengths;
        increment = incrementValue;
        taskCount = strengths.size();
        for (int i = 0; i < (1 << taskCount); ++i) {
            for (int j = 0; j < 100; ++j) {
                dpCache[i][j] = -1;
            }
        }
        long long result = calculateMinTime(0, 1);
        return (result <= 1e12) ? (int)result : -1;
    }
};
