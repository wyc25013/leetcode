#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		bool row_has_zero, col_has_zero = false;
		for(int j = 0; j < col; j++){
			if(matrix[0][j] == 0){
				row_has_zero = true;
				break;
			}
		}
		for(int i = 0; i < row; i++){
			if(matrix[i][0] == 0){
				col_has_zero = true;
				break;
			}
		}

		//projection
		for(int m = 1; m < row; m++){
			for(int n = 1; n < col; n++){
				if(matrix[m][n] == 0){
					matrix[0][n] = 0;
					matrix[m][0] = 0;
				}
			}
		}

		for(int m = 1; m < row; m++){
			if(matrix[m][0] == 0)
				zero_whole_row(m,matrix);
		}

		for(int n = 1; n < col; n++){
			if(matrix[0][n] == 0)
				zero_whole_col(n,matrix);
		}

		if(row_has_zero)
			zero_whole_row(0,matrix);
		if(col_has_zero)
			zero_whole_col(0,matrix);
	}     

	void zero_whole_col(int m,vector<vector<int> >& matrix){
		int row = matrix.size();
		for(int i = 0; i < row; i++)
			matrix[i][m] = 0;
	}

	void zero_whole_row(int n,vector<vector<int> >& matrix){
		int col = matrix[0].size();
		for(int i = 0; i < col; i++)
			matrix[n][i] = 0;
	}
};