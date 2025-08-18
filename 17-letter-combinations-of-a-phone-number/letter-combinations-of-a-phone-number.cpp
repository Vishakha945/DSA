class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        
        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };

        // Backtracking function
        function<void(int)> backtrack = [&](int index) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }

            string letters = phoneMap[digits[index]];
            for (char letter : letters) {
                current.push_back(letter);
                backtrack(index + 1);
                current.pop_back();  // backtrack step
            }
        };

        backtrack(0);
        return result;
    }
};
