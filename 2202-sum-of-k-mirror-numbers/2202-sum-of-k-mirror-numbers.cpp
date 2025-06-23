class Solution {
public:
    bool isPalindrome(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    string toBaseK(long long n, int k) {
        string result = "";
        while (n > 0) {
            result += (n % k) + '0';
            n /= k;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<long long> generatePalindromes(int length) {
        vector<long long> res;

        int half = (length + 1) / 2;
        long long start = pow(10, half - 1);
        long long end = pow(10, half);

        for (long long i = start; i < end; ++i) {
            string first_half = to_string(i);
            string full = first_half;

            for (int j = length % 2 ? half - 2 : half - 1; j >= 0; --j)
                full += first_half[j];

            res.push_back(stoll(full));
        }

        return res;
    }

    long long kMirror(int k, int n) {
        long long sum = 0, count = 0;
        int length = 1;

        while (count < n) {
            vector<long long> palindromes = generatePalindromes(length++);
            for (long long p : palindromes) {
                if (count >= n) break;

                string baseK = toBaseK(p, k);
                if (isPalindrome(baseK)) {
                    sum += p;
                    count++;
                }
            }
        }

        return sum;
    }
};