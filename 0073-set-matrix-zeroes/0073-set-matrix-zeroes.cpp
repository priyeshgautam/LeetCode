class Solution {
public:
/*
 * Solution for Set Matrix Zeroes problem
 * Time Complexity: O(M × N)
 * Space Complexity: O(1)
 * Approach: Use first row and column as markers
 */
void setZeroes(vector<vector<int>>& matrix) {
    // Handle empty matrix
    if (matrix.empty() || matrix[0].empty()) return;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    // Check if first row contains zero
    bool firstRowHasZero = false;
    for(int j = 0; j < cols; j++) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }
    
    // Check if first column contains zero
    bool firstColHasZero = false;
    for(int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }
    
    // Mark zeros on first row and column
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    // Use marks to set zeros (except first row and column)
    for(int i = 1; i < rows; i++) {
        for(int j = 1; j < cols; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    // Set first row to zeros if needed
    if(firstRowHasZero) {
        for(int j = 0; j < cols; j++) {
            matrix[0][j] = 0;
        }
    }
    
    // Set first column to zeros if needed
    if(firstColHasZero) {
        for(int i = 0; i < rows; i++) {
            matrix[i][0] = 0;
        }
    }
} 

};
