class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0 ;
        for(int i = 0 ; i<n ;i++){
            for(int j = i+1 ; j<n ;j++){

                string str1 = words[i];
                string str2 = words[j];
                int s1 = words[i].size();
                int s2 = words[j].size();

                if(s1<=s2){
                    if(str2.substr(0,s1)==str1 && str2.substr(s2-s1)==str1){
                        count++;
                    }

                }

            }
        }
        return count;
    }
};