
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int id = 2;
        unordered_map<int, int> area;
        int max_area = 0;
        
        vector<int> directions = {-1, 0, 1, 0, -1};

        function<int(int, int, int)> dfs = [&](int r, int c, int island_id) {
            if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) return 0;
            grid[r][c] = island_id;
            int size = 1;
            for (int d = 0; d < 4; ++d) {
                size += dfs(r + directions[d], c + directions[d + 1], island_id);
            }
            return size;
        };

        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    area[id] = dfs(r, c, id);
                    max_area = max(max_area, area[id]);
                    id++;
                }
            }
        }
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    unordered_set<int> seen;
                    int new_area = 1;
                    for (int d = 0; d < 4; ++d) {
                        int nr = r + directions[d], nc = c + directions[d + 1];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] > 1) {
                            int island_id = grid[nr][nc];
                            if (!seen.count(island_id)) {
                                new_area += area[island_id];
                                seen.insert(island_id);
                            }
                        }
                    }
                    max_area = max(max_area, new_area);
                }
            }
        }
        return max_area;
    }
};