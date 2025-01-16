class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size(),xor1=0,xor2=0;
        for(int i=0;i<m;i++)xor1^=nums1[i];
        for(int i=0;i<n;i++)xor2^=nums2[i];
        if(!(m&1) && !(n&1))return 0;
        else if(!(m&1))return xor1; 
        else if(!(n&1))return xor2;
        return xor1^xor2;
    }
};