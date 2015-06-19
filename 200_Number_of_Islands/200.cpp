#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
    	int ret = 0;
		int row = grid.size();
		int col = grid[0].size();
		vector<bool> vi(row*col,false);       
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(vi[i*col+j]==true) continue;

				if(grid[i][j] == '1'){
					vi[i*col+j] = true;
					ret++;
					queue<int> ex; ex.push(i*col+j);
					explore(grid,vi,ex,row,col);
				} else vi[i*col+j] = true;
			}
		}
		return ret;
    }

    void explore(vector<vector<char> >& grid, vector<bool>& vi, queue<int>& ex, int row, int col){
    	while(!ex.empty()){
	    	int idx = ex.front() / col; int jdx = ex.front() % col; ex.pop();

	    	if(idx > 0){
	    		if(vi[(idx-1)*col+jdx]==false){
		    		if(grid[idx-1][jdx] == '1'){
						vi[(idx-1)*col+jdx] = true;
						ex.push((idx-1)*col+jdx);
					} else vi[(idx-1)*col+jdx] = true;
	    		}
	    	}

	    	if(idx < row-1){
	    		if(vi[(idx+1)*col+jdx]==false){
		    		if(grid[idx+1][jdx] == '1'){
						vi[(idx+1)*col+jdx] = true;
						ex.push((idx+1)*col+jdx);
					} else vi[(idx+1)*col+jdx] = true;
	    		}
	    	}

	    	if(jdx > 0){
	    		if(vi[idx*col+jdx-1]==false){
		    		if(grid[idx][jdx-1] == '1'){
						vi[idx*col+jdx-1] = true;
						ex.push(idx*col+jdx-1);
					} else vi[idx*col+jdx-1] = true;
	    		}
	    	}

	    	if(jdx < col-1){
	    		if(vi[idx*col+jdx+1]==false){
		    		if(grid[idx][jdx+1] == '1'){
						vi[idx*col+jdx+1] = true;
						ex.push(idx*col+jdx+1);
					} else vi[idx*col+jdx+1] = true;
	    		}
	    	}
    	}
    }
};