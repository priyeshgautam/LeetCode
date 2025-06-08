class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> processed;
        return helper(processed, nums, 0);
    }

    vector<vector<int>> helper(vector<int> processed, vector<int>& nums, int index) {
        if (index == nums.size()) {
            return {processed};
        }

        // Exclude current
        vector<vector<int>> left = helper(processed, nums, index + 1);

        // Include current
        processed.push_back(nums[index]);
        vector<vector<int>> right = helper(processed, nums, index + 1);

        // Combine both
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};