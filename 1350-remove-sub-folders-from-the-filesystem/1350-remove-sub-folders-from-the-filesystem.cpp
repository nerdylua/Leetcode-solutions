class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> res;
        res.push_back(folder[0]);
        for(int j = 1; j<folder.size(); j++){
            if(folder[j].size() < res.back().size() ||
             folder[j][res.back().size()] != '/' ||
             res.back() != folder[j].substr(0,res.back().size()))
            {
                res.push_back(folder[j]);
            }
        }
        return res;
    }
};