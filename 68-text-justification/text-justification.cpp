class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i + 1;
            int lineLength = words[i].size();
            
            // Find how many words can fit in this line
            while (j < n && lineLength + 1 + words[j].size() <= maxWidth) {
                lineLength += 1 + words[j].size();
                j++;
            }
            
            int gaps = j - i - 1;
            string line;
            
            // If last line OR only one word -> left justify
            if (j == n || gaps == 0) {
                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                // Fill remaining spaces
                line += string(maxWidth - line.size(), ' ');
            } else {
                // Distribute spaces
                int totalSpaces = maxWidth;
                for (int k = i; k < j; k++) {
                    totalSpaces -= words[k].size();
                }
                
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;
                
                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += string(spacePerGap + (extraSpaces-- > 0 ? 1 : 0), ' ');
                    line += words[k];
                }
            }
            
            res.push_back(line);
            i = j;
        }
        
        return res;
    }
};
