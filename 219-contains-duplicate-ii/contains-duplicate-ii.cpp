class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp; // stores value -> last index
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k) {
                return true; // found duplicate within k distance
            }
            mp[nums[i]] = i; // update last seen index
        }
        return false;
    }
};
