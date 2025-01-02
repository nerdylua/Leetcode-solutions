class Solution {
private:
    bool isPossibleString(char &a, char &b){
        return (a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
                && (b=='a' || b=='e' || b=='i' || b=='o' || b=='u');
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        vector<int> prefixSum(n);
        vector<int> ans(m);
        int sum = 0;
        for(int i = 0; i<n; i++){
            char a = words[i].front();
            char b = words[i].back();
            if(isPossibleString(a, b)){
                sum++;
            }
            prefixSum[i] = sum;
        }
        for(int i = 0; i<m; i++){
            int start = queries[i][0];
            int end = queries[i][1];

            if(start == 0){
                ans[i] = prefixSum[end];
            } else {
                ans[i] = prefixSum[end] - prefixSum[start-1];
            }
        }

        return ans;
    }
};