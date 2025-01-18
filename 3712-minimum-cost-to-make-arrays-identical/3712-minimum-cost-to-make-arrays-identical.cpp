class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long k) {
        int n = arr.size();
        long long value = 0;
        for (int i = 0; i < n; i++) {
            value += abs(arr[i] - brr[i]);
        }
        if (n > 1) {
            vector<int> sortedArr = arr, sortedBrr = brr;
            sort(sortedArr.begin(), sortedArr.end());
            sort(sortedBrr.begin(), sortedBrr.end());

            long long cost = 0;

            for (int i = 0; i < n; i++) {
                cost += abs(sortedArr[i] - sortedBrr[i]);
            }
            cost += k;
            return min(value, cost);
        }
        return value;
    }
};

