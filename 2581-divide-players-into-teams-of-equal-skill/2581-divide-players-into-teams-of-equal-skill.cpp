class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += skill[i];
        }
        int targetPairSum = totalSum / (n / 2);
        if (totalSum % (n / 2) != 0) {
            return -1;
        }
        sort(skill.begin(), skill.end());

        long long ans = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            if (skill[l] + skill[r] != targetPairSum) {
                return -1;
            }
            ans += (long long)skill[l] * skill[r];
            l++;
            r--;
        }
        return ans;
    }
};