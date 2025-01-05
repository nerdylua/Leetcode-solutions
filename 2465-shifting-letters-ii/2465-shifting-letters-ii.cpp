class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int>Start(n);
        vector<int>End(n);

        for(int i = 0; i < shifts.size(); i++){
            int startIndex = shifts[i][0];
            int endIndex = shifts[i][1];
            if(shifts[i][2] == 1){
                Start[startIndex]++;
                End[endIndex]++;
            }else{
                Start[startIndex]--;
                End[endIndex]--;
            }
        }
        vector<int>v(n);
        v[0] = Start[0];
        for(int i = 1; i < n; i++){
            v[i] = v[i-1] - End[i-1] + Start[i];
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            char c = s[i];
            int x = c - 'a';
            x = (x + v[i])%26;
            if(x < 0) x += 26;
            ans += ('a' + x);
        }
    
        return ans;
    }
};