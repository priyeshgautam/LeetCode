class Solution {
public:
void nextPermutation(vector<int>& nums) {
    int size = nums.size();
    int index = -1;
    // nums = 1 5 4 3 2
    // Step 1: Find the first index from the end where nums[i] < nums[i+1]
    for (int i = size - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            index = i;
            break;
        }
    }

    // index = 0
    // Step 2: If such an index exists, find next greater element and swap
    if (index != -1) {
        for (int i = size - 1; i > index; i--) {
            if (nums[i] > nums[index]) {
                swap(nums[i], nums[index]);
                break;
            }
        }
    }
    // next greater element is 2
    // 2 5 4 3 1

    // Step 3: Reverse the suffix (from index+1 to end)
    reverse(nums.begin() + index + 1, nums.end());
    // 2 1 3 4 5
}
};