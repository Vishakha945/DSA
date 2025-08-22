class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            // Calculate width and height of current container
            int width = right - left;
            int h = min(height[left], height[right]);
            int area = width * h;

            // Update max water
            maxWater = max(maxWater, area);

            // Move the pointer pointing to the smaller height
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxWater;
    }
};
