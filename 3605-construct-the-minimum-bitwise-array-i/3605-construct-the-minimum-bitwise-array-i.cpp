#include <vector>
using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for (int n : nums) {
            bool found = false;
            for (int x = 0; x < n; ++x) {
                if ((x | (x + 1)) == n) {  
                    res.push_back(x);
                    found = true;
                    break;  
                }
            }
            if (!found) {
                res.push_back(-1); 
            }
        }
        return res;
    }
};
