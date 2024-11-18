class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>res(code.size(),0);
        if(k==0) return res;
        int n = code.size();
        for(int i=0;i<n;i++){
        for(int j=1;j<=abs(k);j++){
            if(k>0) res[i] += code[(i+j)%n];
            if(k<0) res[i] += code[(i-j)<0?n+(i-j):(i-j)];
            }
        }
        return res;
    }
};