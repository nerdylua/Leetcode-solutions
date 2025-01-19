class Solution {
public:

    typedef pair<int,pair<int,int>> P;

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n=heightMap.size();
        int m=heightMap[0].size();

        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0;i<m;i++)
        {
            pq.push({heightMap[0][i],{0,i}});
            visited[0][i]=true;
            pq.push({heightMap[n-1][i],{n-1,i}});
            visited[n-1][i]=true;
        }

        for(int i=0;i<n;i++)
        {
            pq.push({heightMap[i][0],{i,0}});
            visited[i][0]=true;
            pq.push({heightMap[i][m-1],{i,m-1}});
            visited[i][m-1]=true;
        }


        int result=0;
        vector<int>row={0,0,-1,1};
        vector<int>col={1,-1,0,0};

        while(!pq.empty())
        {
            int curr_height=pq.top().first;
            int curr_row=pq.top().second.first;
            int curr_col=pq.top().second.second;
            pq.pop();

            for(int i=0;i<4;i++)
            {
                int new_r=curr_row+row[i];
                int new_c=curr_col+col[i];

                if(new_r<0 || new_r>=n || new_c<0 || new_c>=m || visited[new_r][new_c])
                {
                    continue;
                }

                int curr_water=max(curr_height-heightMap[new_r][new_c],0);
                result+=curr_water;
                visited[new_r][new_c]=true;
                pq.push({curr_water+heightMap[new_r][new_c],{new_r,new_c}});
            }
        }
        return result;
    }
};