class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> k_distant_indices;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] == key && abs(i - j) <= k) {
                    k_distant_indices.push_back(i);
                    break; 
                }
            }
        }

        sort(k_distant_indices.begin(), k_distant_indices.end());

        k_distant_indices.erase(unique(k_distant_indices.begin(), k_distant_indices.end()), k_distant_indices.end());

        return k_distant_indices;
    }
};

