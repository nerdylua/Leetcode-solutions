class Solution {
private:
    bool isPrefix(string s, string target) {
        if (target.length() > s.length())
            return false;
        int j = 0;
        for (int i = 0; i < target.length() && j < s.length(); ++i) {
            if (target[i] != s[j])
                return false;
            else
                j++;
        }
        return true;
    }

public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words;
        string h = "";
        for (int i = 0; i < sentence.length(); ++i) {
            if (sentence[i] == ' ') {
                words.push_back(h);
                h = "";
            } else
                h += sentence[i];
        }
        words.push_back(h);
        h = "";
        for (int i = 0; i < words.size(); ++i) {
            if (isPrefix(words[i], searchWord))
                return i + 1;
        }
        return -1;
    }
};