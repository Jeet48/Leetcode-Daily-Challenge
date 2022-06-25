class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
	int m = matrix[0].size();

	int row = -1;
	for (int i = 0; i < n; i++){
		if (matrix[i][0] <= target){
			row = i;
		}
	}

	if (row == -1) return false;

	for (int i = 0; i < m; i++){
		if (matrix[row][i] == target) return true;
	}

	return false;
    }
};