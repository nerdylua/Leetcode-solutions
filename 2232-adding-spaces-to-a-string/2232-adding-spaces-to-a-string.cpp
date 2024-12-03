class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n=spaces.size();
        sort(spaces.begin(),spaces.end());
        string ans=""; int index=0;
        for(int i=0;i<s.length();i++)
        {
            if(index<n and i==spaces[index] )
            {
                ans+=' ';
                i--;
                index++;
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};