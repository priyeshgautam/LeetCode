class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1;
        int rows = matrix.size();
        int cols = matrix[0].size();

        // First pass: mark rows and columns to be zeroed
        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) col0 = 0;
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Second pass: set cells to zero based on marks
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero the first row if needed
        if (matrix[0][0] == 0) {
            for (int j = 0; j < cols; ++j) {
                matrix[0][j] = 0;
            }
        }

        // Zero the first column if needed
        if (col0 == 0) {
            for (int i = 0; i < rows; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
