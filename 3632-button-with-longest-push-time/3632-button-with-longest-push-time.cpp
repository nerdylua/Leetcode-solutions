class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int longestTime = events[0][1];
        int longestButton = events[0][0];
        for (int i = 1; i < events.size(); ++i) {
        int duration = events[i][1] - events[i - 1][1];

        if (duration > longestTime || (duration == longestTime && events[i][0] < longestButton)) {
            longestTime = duration;
            longestButton = events[i][0];
        }
    }
       return longestButton; 
    }
};