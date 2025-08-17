class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        function<void(int, int)> backtrack = [&](int index, int remaining) {
            if (remaining == 0) {
                result.push_back(current);
                return;
            }

            if (index >= candidates.size() || remaining < 0) return;

            // Include the current number
            current.push_back(candidates[index]);
            backtrack(index, remaining - candidates[index]); // Same index, because we can reuse
            current.pop_back();

            // Exclude the current number and move to next
            backtrack(index + 1, remaining);
        };

        backtrack(0, target);
        return result;
    }
};
