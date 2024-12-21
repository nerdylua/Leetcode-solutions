#include <vector>
#include <functional>

class Solution {
public:
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>>& edges, std::vector<int>& values, int k) {
        std::vector<std::vector<int>> graph(n);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        std::vector<bool> visited(n, false);
        int componentCount = 0;
        std::function<long long(int)> dfs = [&](int node) -> long long {
            visited[node] = true;
            long long sum = values[node]; 
            
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    sum += dfs(neighbor); 
                }
            }
            if (sum % k == 0) {
                componentCount++; 
                return 0; 
            }
            return sum; 
        };
        dfs(0);
        
        return componentCount; 
    }
};