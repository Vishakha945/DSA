class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        
        // Split string into words
        while (ss >> word) {
            words.push_back(word);
        }

        // If lengths don’t match, return false
        if (words.size() != pattern.size()) return false;

        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (mp.count(c) && mp[c] != w) return false;   // char already mapped but mismatch
            if (rev.count(w) && rev[w] != c) return false; // word already mapped but mismatch

            mp[c] = w;
            rev[w] = c;
        }

        return true;
    }
};
