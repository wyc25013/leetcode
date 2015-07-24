/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(!row) return false;
        int col = matrix[0].size();
        if(!col) return false;
        
        for(int i = 0; i < row; i++){
            if(helper(matrix[i][0], matrix[i][col-1], target))
                if(searchRow(matrix[i], target)) return true;
        }
        return false;
    }
    
    bool helper(int start, int end, int target){
        if(start <= target && end >= target)
            return true;
        else return false;
    }
    
    bool searchRow(vector<int>& row, int target){
        int l = 0; int r = row.size()-1;
        while(l <= r && row[l] <= target && row[r] >= target){
            if(row[l] == target || row[r] == target)
                return true;
            l++; r--;
        }
        return false;
    }
};
*/
class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchRect(matrix,target,0,0,matrix.size()-1,matrix[0].size()-1);
    }

    bool searchRect(vector<vector<int>>& matrix, int target, 
                               int top, int left, int bottom, int right) {
        //search if the target is inside the rectangular matrix[top:bottom][left:right]
        //each time we discard 1/4 of all elements
        //time complexity O( log(mn)/log(4/3) ) = O(logm + logn)

        if(top>bottom || left>right)
            return false;

        int x = (top+bottom)/2;
        int y = (left+right)/2;
        int center = matrix[x][y];

        if(center > target){
            return
                searchRect(matrix,target,top,left,x-1,right) ||
                searchRect(matrix,target,x,left,bottom,y-1);
        }
        else if(center < target){
            return
                searchRect(matrix,target,x+1,left,bottom,right) ||
                searchRect(matrix,target,top,y+1,x,right);
        }
        else
            return true;
    }
};