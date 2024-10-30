class Solution {
public:
    int solveright(int r,int i,int &n,vector<int>& nums,vector<vector<int>>&dpright){
        if(i >= n)return 0;
        if(dpright[r][i] != -1)return dpright[r][i];
        if(nums[i] < nums[r])return dpright[r][i] = min(1+solveright(r,i+1,n,nums,dpright),solveright(i,i+1,n,nums,dpright));
        else return dpright[r][i] = 1 + solveright(r,i+1,n,nums,dpright);
    }
    int solveleft(int l,int i,int &n,vector<int>& nums,vector<vector<int>>&dpleft){
        if(i < 0)return 0;
        if(dpleft[l][i] != -1)return dpleft[l][i];
        if(nums[i] < nums[l])return dpleft[l][i] = min(1+solveleft(l,i-1,n,nums,dpleft),solveleft(i,i-1,n,nums,dpleft));
        else return dpleft[l][i] = 1 + solveleft(l,i-1,n,nums,dpleft);
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(),m1 = INT_MAX ,m2 = INT_MAX,ans = INT_MAX;
        vector<int>prefix(n),suffix(n);
        for(int i=0;i<n;i++){
            m1 = min(m1,nums[i]);
            prefix[i] = m1;
            m2 = min(m2,nums[n-1-i]);
            suffix[n-1-i] = m2;
        }
        vector<vector<int>>dpleft(1001,vector<int>(1001,-1));
        vector<vector<int>>dpright(1001,vector<int>(1001,-1));
        for(int i=1;i<n-1;i++){
            if(prefix[i-1] < nums[i] && suffix[i+1] < nums[i]){ 
                int left = solveleft(i,i-1,n,nums,dpleft),right = solveright(i,i+1,n,nums,dpright);
                int removals = left + right;
                ans = min(removals,ans);
            }
        }
        return ans;
    }
};