class Solution {
private:
    vector<int> parent;
    int cycleStart = -1, cycleEnd = -1;

    bool DFS(int node, int par, vector<int> adjList[], vector<bool> &visited) {
        visited[node] = true;
        parent[node] = par;

        for (int adj : adjList[node]) {
            if (adj == par) continue; 
            if (visited[adj]) {
                cycleStart = adj;
                cycleEnd = node;
                return true;
            }
            if (DFS(adj, node, adjList, visited)) return true;
        }
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int N = edges.size();
        vector<int> adjList[N + 1]; 

        for (auto &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        parent.assign(N + 1, -1);
        vector<bool> visited(N + 1, false);

        for (int i = 1; i <= N; i++) {
            if (!visited[i] && DFS(i, -1, adjList, visited)) break;
        }

        unordered_set<int> cycleNodes;
        for (int v = cycleEnd; v != cycleStart; v = parent[v]) {
            cycleNodes.insert(v);
        }
        cycleNodes.insert(cycleStart);

        for (int i = edges.size() - 1; i >= 0; i--) {
            if (cycleNodes.count(edges[i][0]) && cycleNodes.count(edges[i][1])) {
                return edges[i];
            }
        }

        return {};
    }
};
