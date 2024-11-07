class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int n = candidates.size(), maxi = INT_MIN;
        
        for(int i=0; i<32; i++) {
            int cnt = 0;
            for(int j=0; j<n; j++) {
                if(candidates[j] & (1 << i)) cnt++;
            }
            maxi = max(maxi, cnt) ;
        }
        
        return maxi ;
    }
};