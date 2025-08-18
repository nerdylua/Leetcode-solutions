class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
private:
    static constexpr double EPS = 1e-6;
    bool dfs(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) return fabs(nums[0] - 24.0) < EPS;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                vector<double> next;
                for (int k = 0; k < n; k++) 
                    if (k != i && k != j) next.push_back(nums[k]);
                for (double res : compute(nums[i], nums[j], i < j)) {
                    next.push_back(res);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b, bool unique) {
        vector<double> results;
        if (unique) {                  
            results.push_back(a + b);
            results.push_back(a * b);
        }
        results.push_back(a - b);
        results.push_back(b - a);
        if (fabs(b) > EPS) results.push_back(a / b);
        if (fabs(a) > EPS) results.push_back(b / a);
        return results;
    }
};