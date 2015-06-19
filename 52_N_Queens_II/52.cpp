#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
		int result = 0;
		vector<int> chessboard;
		for(int i = 0; i < n; i++)
			chessboard.push_back(-1);

		int idx_i = 0;
		for(int idx_j = 0; idx_j < n; idx_j++){
			chessboard[idx_i] = idx_j;
			recursive(chessboard,idx_i+1,n,result);
			chessboard[idx_i] = -1;
		}	

		return result;
    }

    void recursive(vector<int>& chessboard, int idx_i, int n, int& result){
    	if(idx_i == n){
    		result++;
    		return;
    	}
    	else{
	    	for(int idx_j = 0; idx_j < n; idx_j++){
	    		if(helper(chessboard,idx_i,idx_j) == false)
	    			continue;
				chessboard[idx_i] = idx_j;
				recursive(chessboard,idx_i+1,n,result);
				chessboard[idx_i] = -1;
			}	
    	}
    }

    bool helper(vector<int>& chessboard, int idx_i, int idx_j){
        for(int i = 0; i < idx_i; i++){
            if(chessboard[i] == idx_j)
                return false;
            if(fabs(idx_i-i) == fabs(chessboard[i]-idx_j))
                return false;
        }
        return true;
    }
};

int main(){
	Solution soln;
	cout<<soln.totalNQueens(8)<<endl;
}