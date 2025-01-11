class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if( n < k) return false;
        if( n == k) return true;

        unordered_map<char,int> mp;
        for(auto it: s) mp[it]++;

        int non_pairs = 0;
        for(auto it: mp){
            int num = it.second;
            non_pairs += (num%2);
        }
 
        if(non_pairs > k) return false;
        return true;
    }
};