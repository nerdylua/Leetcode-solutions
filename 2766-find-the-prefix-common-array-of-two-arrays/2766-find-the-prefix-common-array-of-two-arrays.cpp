class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<bool> hash(n, false);
        int common = 0;
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (hash[A[i]]) common++;
            else (hash[A[i]] = true);
            if (hash[B[i]]) common++;
            else (hash[B[i]] = true);
            res[i] = common;
        }

        return res;
    }
};