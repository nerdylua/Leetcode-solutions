class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        unordered_map<int, int> map;
        for(auto val : arr)
        {
            int mod = ((val % k) + k) % k;
            map[mod]++;
        }
        for(auto [rem, count] : map)
        {
            if(not rem) 
            {
                if(count % 2) return false; 
            }
            else if(rem + rem == k)
            {
                if(count % 2) return false;  
            }
            else if(map[rem] != map[k - rem]) return false; 
        }
        return true;
    }
};