class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 1;
        vector<vector<bool>> similarity(m, vector<bool>(n,true));
        map<vector<bool>, int> mp; 
        for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(matrix[i][j] != matrix[i][0])
                    similarity[i][j] = false;
                }
                mp[similarity[i]]++;
            }
            for(auto it = mp.begin(); it != mp.end(); it++)
            ans = max(ans,it->second);
            return ans;
    }
};