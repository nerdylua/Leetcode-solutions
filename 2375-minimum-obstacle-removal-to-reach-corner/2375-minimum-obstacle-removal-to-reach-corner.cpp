class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        priority_queue< pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        pq.push({0, {0, 0}});

        int ans = 1e9;
        while (!pq.empty()) {
            auto top = pq.top();
            int x = top.second.first;
            int y = top.second.second;
            int step = top.first;
            pq.pop();
               if (x == n - 1 and y == m - 1) {
                  return step;
                }
             
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                
             
                if ( new_x >= 0 and new_x < n and new_y >= 0 and new_y < m && !vis[new_x][new_y] ) {
                    vis[new_x][new_y]=1;
                    if (grid[new_x][new_y] == 0) {
                        pq.push({step, {new_x, new_y}});
                    } else {
                        pq.push({step + 1, {new_x, new_y}});
                    }
                }
            }
        }
        return ans;
    }
};