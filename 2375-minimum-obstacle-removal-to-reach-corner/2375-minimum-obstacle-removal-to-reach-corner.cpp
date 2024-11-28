class Solution {
public:

    typedef pair<int, int> P;
    bool isValid(int row, int col, int n, int m){
        
        if(row < 0 || row >= n || col < 0 || col >= m){
            return false;
        }

        return true;
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, P>, vector<pair<int, P>>,greater<pair<int, P>>> q;

        q.push({grid[0][0], {0, 0}});

        dist[0][0] = grid[0][0];

        while(!q.empty()){

            int steps = q.top().first;
            int x     = q.top().second.first;
            int y     = q.top().second.second;
            q.pop();

            if(x == n-1 && y == m-1){
                return steps;
            }

            for(auto &dir: directions){

                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(isValid(new_x, new_y, n, m) && dist[new_x][new_y] > steps + grid[new_x][new_y]){
                    dist[new_x][new_y] = steps + grid[new_x][new_y];

                    q.push({dist[new_x][new_y], {new_x, new_y}});
                }

            }
        }

        return -1;
    }
};