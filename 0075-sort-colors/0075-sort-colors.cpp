class Solution {
public:
/*
 * Solution for Sort Colors (Dutch National Flag Problem)
 * Time Complexity: O(n) - single pass algorithm
 * Space Complexity: O(1) - in-place sorting
 * 
 * The algorithm maintains three pointers:
 * - low: boundary for 0s (all elements before low are 0)
 * - mid: current element being examined
 * - high: boundary for 2s (all elements after high are 2)
 */
void sortColors(vector<int>& nums) {
    // Handle empty array
    if (nums.empty()) return;
    
    // Initialize pointers
    int low = 0;          // boundary for 0s
    int mid = 0;          // current element
    int high = nums.size() - 1;  // boundary for 2s
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            // If we find 0, swap with low boundary and move both pointers
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            // If we find 1, just move mid pointer
            mid++;
        }
        else if (nums[mid] == 2) {
            // If we find 2, swap with high boundary and move high pointer
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}


};