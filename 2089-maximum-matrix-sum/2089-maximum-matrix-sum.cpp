class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int neg = 0, is0 = 0, min = abs(matrix[0][0]);
        long long res = 0;
        int len = matrix.size();
        for(int i=0; i<len; i++)
        {
            for(int j=0; j<len; j++)
            {
                if(matrix[i][j]<0)
                {
                    res -= matrix[i][j];
                    matrix[i][j] *= -1;
                    neg++;
                }
                else
                    res += matrix[i][j];
                if(matrix[i][j]<min) min = matrix[i][j];
                if(matrix[i][j]==0) {
                    is0 = 1;
                }
            }
        }
        if(neg%2 == 0 || is0 == 1) return res;
        else return res - 2*min;
    }
};