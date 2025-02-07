class Solution 
{
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) 
    {
        map<int,int> ballColor, colorBall;
        vector<int> ans(queries.size());
        int i=0;
        for(auto q: queries)
        {
            int ball=q[0];
            int color=q[1];
            if(ballColor.find(ball)!=ballColor.end())
            {
                int remove=ballColor[ball];
                colorBall[remove]--;
                if(colorBall[remove]==0) colorBall.erase(remove);
                ballColor.erase(ball);
            }
            ballColor[ball]=color;
            colorBall[color]++;
            ans[i++]=colorBall.size();
        }
        return ans;
    }
};