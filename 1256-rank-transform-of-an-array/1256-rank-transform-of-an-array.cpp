class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> Rank;  
        vector<int> sorted = arr; 
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
        
        for (int i = 0; i < sorted.size(); i++) {
            Rank[sorted[i]] = i + 1;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = Rank[arr[i]];
        }
        return arr;  
    }
};