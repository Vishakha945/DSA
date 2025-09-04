class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        // Binary search
        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element > right element,
            // min must be in right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Else, min is in left half (including mid)
            else {
                right = mid;
            }
        }
        // Left will end up pointing to the minimum
        return nums[left];
    }
};
