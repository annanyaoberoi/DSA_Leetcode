class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int rows = (int)matrix.size();
        int cols = (int)matrix[0].size();
        int row = 0, col = cols - 1;
        while (row < rows && col >= 0) {
            int current = matrix[row][col];
            if (current == target) return true;
            if (current > target) col--;
            else row++;
        }return false;
    }
};