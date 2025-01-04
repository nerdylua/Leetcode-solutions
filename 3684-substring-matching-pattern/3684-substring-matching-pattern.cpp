class Solution {
public:
    bool hasMatch(string s, string p) {
        size_t stidx = p.find('*');
        if (stidx == string::npos) 
            return s == p;

        string lft = p.substr(0, stidx);
        string rgt = p.substr(stidx + 1);

        size_t lftidx = s.find(lft);
        if (lftidx == string::npos) 
            return false;

        size_t rgtidx = s.rfind(rgt);
        if (rgtidx == string::npos) 
            return false;

        return lftidx + lft.length() <= rgtidx;
    }
};