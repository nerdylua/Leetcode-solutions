class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> cand;
        for (int i = 0; i < n; i++) cand.insert(i);
        for (auto& e : edges) {
            cand.erase(e[1]);
        }
        return cand.size() == 1 ? *cand.begin() : -1;
    }
};