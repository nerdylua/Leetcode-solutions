class Solution {
public:
    char findKthBit(int n, int k) 
    {
        string zero = "0";
        for(int _ = 1; _ < n; _++)
        {
            string one = "1";
            int size = zero.size();
            for(int i = size - 1; i >= 0; i--)
                one += (zero[i] == '0' ? '1' : '0');
            zero += one;
        }
        return zero[k - 1];
    }
};