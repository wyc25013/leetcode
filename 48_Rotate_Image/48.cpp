class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i = 0; i < size/2; i++){
            for(int j = 0; j < size; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[size-1-i][j];
                matrix[size-1-i][j] = tmp;
            }
        }
        
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};