/*
 * Combination Sum Problem
 * Time Complexity: O(2^t * k) where t is target and k is average length of combination
 * Space Complexity: O(k * x) where k is average length and x is number of combinations
 * Auxiliary Space: O(target) for recursion stack
 * 
 * Problem: Find all unique combinations of candidates where the chosen numbers sum to target.
 * Each number can be used unlimited number of times.
 */
class Solution {
private:
    void findCombination(int index, int target, vector<int>& candidates, 
                        vector<vector<int>>& result, vector<int>& current) {
        // Base case: if target is achieved
        if (target == 0) {
            result.push_back(current);
            return;
        }
        
        // Base case: if we've processed all elements or target becomes negative
        if (index >= candidates.size() || target < 0) {
            return;
        }
        
        // Decision 1: Include current element
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            // Recursive call with same index as we can reuse the number
            findCombination(index, target - candidates[index], 
                          candidates, result, current);
            current.pop_back(); // backtrack
        }
        
        // Decision 2: Exclude current element
        findCombination(index + 1, target, candidates, result, current);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        
        // Handle edge cases
        if (candidates.empty() || target <= 0) {
            return result;
        }
        
        // Sort to handle candidates in ascending order (optional, helps in some cases)
        sort(candidates.begin(), candidates.end());
        
        findCombination(0, target, candidates, result, current);
        return result;
    }
}; 
