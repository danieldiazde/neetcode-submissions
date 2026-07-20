class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i) {
            if (seen[nums[i]] == 1) return true;
            seen[nums[i]]++;
        }
        return false;

    }
};