class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int rows = grid.size();
        int cols = grid[0].size();
        int maxMask = 15;
        vector<vector<vector<int>>> ways(rows, vector<vector<int>>(cols, vector<int>(maxMask + 1, 0)));
        ways[0][0][grid[0][0]] = 1;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                for (int mask = 0; mask <= maxMask; ++mask) {
                    if (ways[r][c][mask] > 0) {
                        if (c + 1 < cols) {
                            int newMask = mask ^ grid[r][c + 1];
                            ways[r][c + 1][newMask] = (ways[r][c + 1][newMask] + ways[r][c][mask]) % MOD;
                        }
                        if (r + 1 < rows) {
                            int newMask = mask ^ grid[r + 1][c];
                            ways[r + 1][c][newMask] = (ways[r + 1][c][newMask] + ways[r][c][mask]) % MOD;
                        }
                    }
                }
            }
        }

        return ways[rows - 1][cols - 1][k];
    }
};
