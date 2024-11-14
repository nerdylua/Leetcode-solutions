class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int right = 1, left = 1, sz = quantities.size();
        for (int i = 0; i < sz; i++) {
            right = max(right, quantities[i]);
        }
        int result = right;
        while (left <= right) {
            if (left == right) {
                if (need(quantities, left) <= n)
                    result = min(result, left);
                break;
            }
            int mid = left + (right - left) / 2;
            if (need(quantities, mid) <= n) {
                right = mid;
                result = min(result, mid);
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
    int need(vector<int>& quant, int many) {
        int sz = quant.size();
        int res = 0;
        for (int i = 0; i < sz; i++) {
            res += (quant[i] % many > 0) + (quant[i] / many);
        }
        return res;
    }
};