class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()) return "";

        unordered_map<char,int> freq;
        for(char c : t) freq[c]++; // Count chars in t

        int required = freq.size(); // how many unique chars we need
        int formed = 0;             // how many chars currently satisfied
        unordered_map<char,int> window;

        int l = 0, r = 0;
        int minLen = INT_MAX;
        int start = 0;

        while(r < s.size()) {
            char c = s[r];
            window[c]++;
            
            // If current char satisfies one requirement
            if(freq.count(c) && window[c] == freq[c]) {
                formed++;
            }

            // Try to shrink from left
            while(l <= r && formed == required) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }
                char leftChar = s[l];
                window[leftChar]--;
                if(freq.count(leftChar) && window[leftChar] < freq[leftChar]) {
                    formed--;
                }
                l++;
            }
            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
