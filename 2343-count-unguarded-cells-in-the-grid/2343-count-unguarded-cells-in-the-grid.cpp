class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int> (n, 0));
        for(auto i : guards) grid[i[0]][i[1]] = 2;
        for(auto i : walls) grid[i[0]][i[1]] = 2;
        for(auto i : guards) {
            left(grid, i[0], i[1]);
            right(grid, i[0], i[1]);
            up(grid, i[0], i[1]);
            down(grid, i[0], i[1]);
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) ans++;
            }
        }

        return ans;
    }
private:
    void left(vector<vector<int>>& grid, int i, int j) {
        j--; 
        while (j >= 0 && grid[i][j] != 2) { 
            if (grid[i][j] == 0) grid[i][j] = 1; 
            j--;
        }
    }
    void right(vector<vector<int>>& grid, int i, int j) {
        j++; 
        while (j < grid[0].size() && grid[i][j] != 2) {
            if (grid[i][j] == 0) grid[i][j] = 1;
            j++;
        }
    }
    void up(vector<vector<int>>& grid, int i, int j) {
        i--; 
        while (i >= 0 && grid[i][j] != 2) {
            if (grid[i][j] == 0) grid[i][j] = 1;
            i--;
        }
    }
    void down(vector<vector<int>>& grid, int i, int j) {
        i++; 
        while (i < grid.size() && grid[i][j] != 2) {
            if (grid[i][j] == 0) grid[i][j] = 1;
            i++;
        }
    }
};