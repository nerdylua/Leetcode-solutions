class Solution {
private:
    int getTop( int i, int j, vector<vector<int>> &fruits, vector<vector<int>> &dp ) {
        if( dp[i][j] != -1 ) return dp[i][j];
        return dp[i][j] = fruits[i][j] + max( { getTop( i+1, j-1, fruits, dp ),
                                                getTop( i+1, j, fruits, dp ),
                                                getTop( i+1, j+1, fruits, dp ) } );
    }
    int getBottom( int i, int j, vector<vector<int>> &fruits, vector<vector<int>> &dp ) {
        if( dp[i][j] != -1 ) return dp[i][j];
        return dp[i][j] = fruits[i][j] + max( { getBottom( i-1, j+1, fruits, dp ),
                                                getBottom( i, j+1, fruits, dp ),
                                                getBottom( i+1, j+1, fruits, dp ) } );
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int res = 0, n = fruits.size();
        for( int i=0; i<n; i++ ) {
            res += fruits[i][i];
            fruits[i][i] = 0;
        }
        vector<vector<int>> dp1( n+1, vector<int>( n+1, 0 ) ), dp2( n+1, vector<int>( n+1, 0 ) );
        for( int i=0; i<n; i++ ) {
            for( int j=i+1; j<n; j++ ) {
                dp1[i][j] = -1;
                dp2[j][i] = -1;
            }
        }
        return res + getTop( 0, n-1, fruits, dp1 ) + getBottom( n-1, 0, fruits, dp2 );
    }
};