class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev_graph(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int u = i;
                int v = graph[i][j];
                rev_graph[v].push_back(u);
                
            }
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rev_graph[i].size();j++)
            {
                indegree[rev_graph[i][j]]++;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty())
        {
            int u = q.front();
            ans.push_back(u);
            q.pop();
            for(int i=0;i<rev_graph[u].size();i++)
            {
                indegree[rev_graph[u][i]]--;
                if(indegree[rev_graph[u][i]] == 0)
                    q.push(rev_graph[u][i]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};