class Solution {
public:
    int calculateFish(vector<vector<int>>& grid, int i, int j, int row, int col) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == 0) {
            return 0;
        }
        
        int fishCount = grid[i][j];
        grid[i][j] = 0;

        fishCount += calculateFish(grid, i - 1, j, row, col); 
        fishCount += calculateFish(grid, i + 1, j, row, col); 
        fishCount += calculateFish(grid, i, j - 1, row, col); 
        fishCount += calculateFish(grid, i, j + 1, row, col); 
        
        return fishCount;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxFish = 0;


        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] > 0) {
                    maxFish = max(maxFish, calculateFish(grid, i, j, row, col));
                }
            }
        }
        return maxFish;
    }
};