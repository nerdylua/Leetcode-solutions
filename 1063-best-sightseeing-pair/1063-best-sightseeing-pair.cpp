class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> vec(n,0); 
        vec[0]=values[0] + 0; 

        for(int i=1;i<n;i++){
            vec[i]=max(values[i]+i,vec[i-1]); 

        }

        int res=0;

        for(int j=1;j<n;j++){
            int a= values[j] - j;
            int b =vec[j-1]; 
            res=max(res,a+b);
        }
        return res;



    } 
};