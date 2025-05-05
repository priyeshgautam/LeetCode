class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::unordered_map<int, int> count;
        for (int num : nums) {
            if (++count[num] > 1) {
                return num;
            }
        }
        return -1; // No duplicate found
    }
};
