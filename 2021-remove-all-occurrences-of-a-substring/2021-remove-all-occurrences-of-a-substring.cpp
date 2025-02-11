class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            size_t index = s.find(part);
            s.erase(index, part.length()); 
        }
        return s;
    }
};