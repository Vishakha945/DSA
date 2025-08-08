
class Solution {
public:
    string reverseWords(string s) {
        // Remove extra spaces and split words
        stringstream ss(s);
        string word;
        vector<string> words;

        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the word list
        reverse(words.begin(), words.end());

        // Rebuild string
        string result;
        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) result += " ";
            result += words[i];
        }

        return result;
    }
};