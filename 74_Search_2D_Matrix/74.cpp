#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		int col = matrix[0].size();
		int r = 0;
		while(1){
			if(matrix[r][0] == target)
				return true;
			else if(matrix[r][0] < target){
				if(r == row-1)
					break;
				r++;
			}
			else{
				if(r == 0)
					return false;
				else{
				    r--;
				    break;
				}
			}
		}      

		if(matrix[r][col-1] == target)
			return true;
		else if(matrix[r][col-1] < target)
			return false;
		else{
			for(int i = 1; i < col-1; i++){
				if(matrix[r][i] == target)
					return true;
				if(matrix[r][i] > target)
					return false;
			}
			return false;
		}  
    }
};