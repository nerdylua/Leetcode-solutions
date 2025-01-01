
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.empty()) return true;                     
        if (s1.size() > s2.size()) return false;         

        vector<int> s1freq(26, 0), wFreq(26, 0);         

        for (char ch : s1) {
            s1freq[ch - 'a']++;
        }

        int window = s1.size();

        for (int i = 0; i < window; i++) {
            wFreq[s2[i] - 'a']++;
        }

        if (s1freq == wFreq) return true;

        for (int i = window; i < s2.size(); i++) {
            wFreq[s2[i] - 'a']++;                  
            wFreq[s2[i - window] - 'a']--;         

            if (s1freq == wFreq) return true;
        }

        return false;                               
    }
};