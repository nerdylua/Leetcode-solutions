class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1)
        return 1;

        int returner{},curIn=1,curDec=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                curDec++;
            }else{
                curDec=1;
            }
            if(nums[i]>nums[i-1]){
                curIn++;
            }else{
                curIn=1;
            }

            returner=max(returner,max(curIn,curDec));
        }
        return returner;

    }
};