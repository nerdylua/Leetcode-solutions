class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int smalli = events[0][0];
        int maxi = events[0][1];
        for (int i = 1; i < events.size(); i++){
            int totaltime = events[i][1] - events[i-1][1]; // calc the time diff
            if (totaltime > maxi || (totaltime == maxi && events[i][0] < smalli)){
                maxi = totaltime;
                smalli = events[i][0];
            }
        }
        return smalli;
    }
};