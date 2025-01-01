class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        int size=0;
        int miss=0;
        int ans = 0;
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(ch == '('){
                size++;
            }
            else if(size>0){
                size--;
            }
            else if(size==0){
                miss++;
            }
        }
        ans = size+miss;
        return ans;
    }
};