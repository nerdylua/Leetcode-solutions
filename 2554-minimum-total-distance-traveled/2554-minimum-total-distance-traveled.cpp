class Solution {
public:
    long long maxi = 1e16; 
private:
    long long solve(int r, int f, vector<int>& robot, vector<int>& v, vector<vector<long long>>& dp) {
        if (r == robot.size()) {
            return 0; 
        }
        if (f == v.size()) {
            return maxi;
        }
        if (dp[r][f] != -1) {
            return dp[r][f];  
        }
        long long incl = abs(robot[r]-v[f]) + solve(r + 1, f + 1, robot, v, dp);
        long long excl = solve(r, f + 1, robot, v, dp);  

        return dp[r][f] = min(incl, excl);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<int> v;
        for (auto i : factory) {
            int pos = i[0], lim = i[1];
            for (int j = 0; j < lim; j++) {
                v.push_back(pos);  
            }
        }

        vector<vector<long long>> dp(robot.size() + 1, vector<long long>(v.size() + 1, -1));

        return solve(0, 0, robot, v, dp);
    }
};