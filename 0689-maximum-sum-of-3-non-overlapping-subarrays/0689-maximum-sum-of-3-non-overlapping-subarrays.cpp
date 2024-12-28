class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        vector<int> subSum(n,0);
        int currSum = 0;
        for(int i=0;i<n;i++)
        {
            if(i >= k)
                currSum -= nums[i-k];
            currSum += nums[i];

            if(i >= k-1)
                subSum[i-k+1] = currSum; 
        }
        vector<int> leftMax(n,0) , rightMax(n,0);
        int leftInd = 0 , rightInd = n-1 , maxSum = 0;
        for(int i=0;i<n;i++)
        {
            if(subSum[i] > subSum[leftInd])
                leftInd = i;
            leftMax[i] = leftInd;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(subSum[i] >= subSum[rightInd])
                rightInd = i;
            rightMax[i] = rightInd;
        }
        for(int i=k;i<n-k;i++)
        {
            currSum = subSum[i] + subSum[leftMax[i-k]] + subSum[rightMax[i+k]];
            if(currSum > maxSum)
            {
                maxSum = currSum;
                res = {leftMax[i-k] , i , rightMax[i+k]};
            }
        }
        return res;
        
    }
};