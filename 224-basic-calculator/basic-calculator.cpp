class Solution {
public:
    int calculate(string s) {
        int result = 0;    // Final answer
        int num = 0;       // Current number
        int sign = 1;      // Current sign (+1 or -1)
        stack<int> st;     // To handle '(' and ')'

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // make number
            } 
            else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;  // next number will be positive
            } 
            else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1; // next number will be negative
            } 
            else if (c == '(') {
                // Save current result and sign
                st.push(result);
                st.push(sign);
                result = 0;  // reset for inside bracket
                sign = 1;
            } 
            else if (c == ')') {
                result += sign * num;
                num = 0;
                result *= st.top(); st.pop(); // pop sign
                result += st.top(); st.pop(); // pop old result
            }
        }

        // Add last number
        result += sign * num;
        return result;
    }
};
