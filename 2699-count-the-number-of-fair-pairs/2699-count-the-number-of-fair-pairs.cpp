class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long cnt=0;
        int n=nums.size();
        int i=0,j=n-1,t=n-1;
        sort(nums.begin(),nums.end());
        while(i<j)
        {
            if((nums[i]+nums[j])>upper)
            {
                j--;
                t=min(j,t);
                continue;
            }
            t=max(t,i);
            while(t>i&&((nums[i]+nums[t])>=lower)&&((nums[i]+nums[t])<=upper))
            {
                t--;
            }
            cnt+=((j-(t)));
            i++;
        }
        return cnt;
    }
};
