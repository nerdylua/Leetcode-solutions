class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        vector<int>arr;
        int ans=0;
        map<int,int>mp;  
        vector<long long int>perm(nums.size()+1,1);
        for(int i=2;i<nums.size()+1;i++){
            perm[i]=i*(i-1);
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)arr.push_back(nums[i]*nums[j]);
        }

        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto [k,v]:mp){
            if(v>=2)ans+=(4*perm[v]);}
        return ans;
    }
};