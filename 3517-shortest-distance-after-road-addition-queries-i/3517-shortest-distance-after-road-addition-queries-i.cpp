class Solution {
public:
    int bfs(vector<vector<int>> &ls,int n){
        queue<int> q;
        int step = 0;
        q.push(0);
        vector<int> visit(n+1,0);
        while(!q.empty()){
            int size = q.size();
            while(size){
                auto it = q.front();
                q.pop();
                if(it == n){
                    return step;
                }
                for(auto a : ls[it]){
                    if(visit[a] == 0){
                        q.push(a);
                        visit[a] = 1;
                    }
                }
                size--;
            }
            step++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> ls(n,vector<int>());
        for(int i = 0; i < n-1; i++){
            ls[i].push_back(i+1);
        }
        for(int i = 0; i < queries.size(); i++){
            ls[queries[i][0]].push_back(queries[i][1]);
            ans.push_back(bfs(ls,n-1));
        }
        return ans;
    }
};