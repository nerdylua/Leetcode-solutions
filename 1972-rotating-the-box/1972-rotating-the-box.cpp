class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; i++) {
            int stones = 0;
            for (int j = 0; j < n; j++) {
                if (box[i][j] == '#')
                    stones++;
                if (box[i][j] == '*') {
                    ans[j][m - 1 - i] = '*';
                    if (stones)
                        ans[j - stones][m - 1 - i] = '#';
                    stones = 0;
                }
            }
            if (stones && box[i][n - 1] != '*') {
                ans[n - stones][m - 1 - i] = '#';
            }
        }
        for (int i = 0; i < m; i++) {
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (ans[j][i] == '*')
                    flag = false;
                if (flag) {
                    ans[j][i] = '#';
                }
                if (ans[j][i] == '#') {
                    flag = true;
                }
            }
        }
        return ans;
    }
};