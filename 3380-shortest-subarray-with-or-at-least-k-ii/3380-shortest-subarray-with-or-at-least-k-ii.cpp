class Solution {
public:
    void perfomOperation(int &num,int& orValue,vector<int> &bitcnt){
        orValue=(orValue|num);
        for(int i=0;i<32;i++){
            if(num&(1<<i))
                bitcnt[i]+=1;
        }
    }
    void revertOrOperation(int &num,int& orValue,vector<int> &bitcnt){
        for(int i=0;i<32;i++){
            if(num&(1<<i))
                bitcnt[i]-=1;
            if(bitcnt[i]==0)
                orValue=orValue&(~(1<<i));
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MAX;
        int orValue=0;
        vector<int> bitcnt(32,0);
        int l=0;
        int r=0;
        while(r<nums.size()){
            perfomOperation(nums[r],orValue,bitcnt);
            while(l<=r&&orValue>=k){
                ans=min(ans,r-l+1);
                revertOrOperation(nums[l],orValue,bitcnt);
                l++;
            }
            r++;
        }
        return (ans==INT_MAX)?-1:ans;
    }
};