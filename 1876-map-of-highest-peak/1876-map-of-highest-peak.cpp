class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        vector<vector<int>> height(m,vector<int>(n,0));
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int dr[]={-1,0,0,1};
        int dc[]={0,1,-1,0};
        while(!q.empty()){
            int x=q.front().second.first,y=q.front().second.second;
            int s=q.front().first;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dr[i],ny=y+dc[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                    q.push({s+1,{nx,ny}});
                    height[nx][ny]=s+1;
                    vis[nx][ny]=1;
                }
            }
        }

        return height;

    }
};