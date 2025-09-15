class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') {
                st.push(c); // push opening bracket
            } else {
                if(st.empty()) return false; // no opening for this closing
                char top = st.top();
                st.pop();
                if((c == ')' && top != '(') || 
                   (c == '}' && top != '{') || 
                   (c == ']' && top != '[')) {
                    return false; // mismatch
                }
            }
        }
        return st.empty(); // valid if no unmatched opening
    }
};
