class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int product = productCalc(n);
            if (product % t == 0) {
                return n;
            }
            n++;
        }
    }

private:
    int productCalc(int num) {
        int product = 1;
        for (char digit : std::to_string(num)) {
            product *= (digit - '0');  
        }
        return product;
    }
};
