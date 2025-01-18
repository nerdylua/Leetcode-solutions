class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        set<pair<int, int>> vis;
        pq.push({0, 0, 0});
        int dir[5]={-1, 0, 1, 0, -1};
        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();

            if(vis.count({v[1], v[2]}))
                continue;
            else vis.insert({v[1], v[2]});

            if(v[1] == m-1 && v[2] == n-1)
                return v[0];
            int a, b;
            if(grid[v[1]][v[2]] == 1)
                a = v[1], b = v[2]+1;
            else if(grid[v[1]][v[2]] == 2)
                a = v[1], b = v[2]-1;
            else if(grid[v[1]][v[2]] == 3)
                a = v[1]+1, b = v[2];
            else a = v[1]-1, b = v[2];
            for(int i=1; i<5; i++){
                int x = v[1] - dir[i-1];
                int y = v[2] - dir[i];
                if(!vis.count({x, y}) && x >= 0 && y >= 0 && x < m && y < n){
                    if(x == a && b == y)
                        pq.push({v[0], x, y});
                    else pq.push({v[0]+1, x, y});
                }
            }
        }
        return 0;
    }
};