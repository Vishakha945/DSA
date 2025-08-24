class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        if (s.size() < totalLen) return result;

        unordered_map<string, int> wordMap;
        for (auto &w : words) wordMap[w]++;

        // We need to check for each possible starting offset (0 to wordLen-1)
        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> seen;

            for (int j = i; j + wordLen <= s.size(); j += wordLen) {
                string word = s.substr(j, wordLen);

                if (wordMap.count(word)) {
                    seen[word]++;
                    count++;

                    // If word frequency exceeds expected, shrink from left
                    while (seen[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    // If all words matched
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } else {
                    // Reset window
                    seen.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return result;
    }
};
