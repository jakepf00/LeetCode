class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = matrix.size() * matrix[0].size() - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int i = mid / matrix[0].size();
            int j = mid % matrix[0].size();
            if (matrix[i][j] < target) low = mid + 1;
            else if (matrix[i][j] > target) high = mid - 1;
            else return true;
        }
        return false;
    }
};
