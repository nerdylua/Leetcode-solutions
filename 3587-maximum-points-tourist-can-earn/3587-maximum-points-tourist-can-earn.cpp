class Solution {
public:
    int maxScore(int n, int k,  vector< vector<int>>& stayScore,  vector< vector<int>>& travelScore) {
        int days = k;
         vector< vector<int>> dp(days + 1,  vector<int>(n, 0));
        for (int day = 0; day < days; ++day) {
            for (int currCity = 0; currCity < n; ++currCity) {
                dp[day + 1][currCity] =  max(dp[day + 1][currCity], dp[day][currCity] + stayScore[day][currCity]);
                for (int destCity = 0; destCity < n; ++destCity) {
                    if (currCity != destCity) {
                        dp[day + 1][destCity] =  max(dp[day + 1][destCity], dp[day][currCity] + travelScore[currCity][destCity]);
                    }
                }
            }
        }
        int maxPoints = 0;
        for (int city = 0; city < n; ++city) {
            maxPoints =  max(maxPoints, dp[days][city]);
        }

        return maxPoints;
    }
};
