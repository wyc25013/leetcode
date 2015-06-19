#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > result;
		vector<bool> chessboard;
		for(int i = 0; i < n*n; i++)
			chessboard.push_back(true);

		int idx_i = 0;
		for(int idx_j = 0; idx_j < n; idx_j++){
			vector<bool> dirtyboard = helper(chessboard,idx_i,idx_j,n);
			vector<string> ret(n, string(n, '.'));
			ret[idx_i][idx_j] = 'Q';
			recursive(dirtyboard,idx_i+1,n,ret,result);
			ret[idx_i][idx_j] = '.';
		}	

		return result;
    }

    void recursive(vector<bool>& chessboard, int idx_i, int n, vector<string>& ret, vector<vector<string> >& retset){
    	if(idx_i == n){
    		retset.push_back(ret);
    		return;
    	}
    	else{
	    	for(int idx_j = 0; idx_j < n; idx_j++){
	    		if(chessboard[idx_i*n+idx_j] == false)
	    			continue;
				vector<bool> dirtyboard = helper(chessboard,idx_i,idx_j,n);
				ret[idx_i][idx_j] = 'Q';
				recursive(dirtyboard,idx_i+1,n,ret,retset);
				ret[idx_i][idx_j] = '.';
			}	
    	}
    }

    vector<bool> helper(vector<bool> chessboard, int idx_i, int idx_j, int n){
    	for(int i = 0; i < n; i++){
    		chessboard[i*n+idx_j] = false;
//    		chessboard[idx_i*n+i] = false;
    	}
    	for(int i = 1; idx_i+i < n && idx_j+i < n; i++)
    		chessboard[(idx_i+i)*n+idx_j+i] = false;
    	for(int i = 1; idx_i+i < n && idx_j-i >= 0; i++)
    		chessboard[(idx_i+i)*n+idx_j-i] = false;
// no need to do 
//    	for(int i = 1; idx_i-i >= 0 && idx_j+i < n; i++)
//    		chessboard[(idx_i-i)*n+idx_j+i] = false;
// 	  	for(int i = 1; idx_i-i >= 0 && idx_j-i >= 0; i++)
//    		chessboard[(idx_i-i)*n+idx_j-i] = false;
    	return chessboard;
    }
};

int main(){
	Solution soln;
	vector<vector<string> > ret = soln.solveNQueens(9);
	for(int i = 0; i < ret.size(); i++){
		for(int j = 0; j < 9; j++){
				cout<<ret[i][j]<<endl;
		}
		cout<<endl;
	}
}