#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
		int idx_i, idx_j = 0;	        
		int size_i = matrix.size();
		if(size_i == 0)
		    return ret;
		int size_j = matrix[0].size();
		if(size_j == 0)
		    return ret;
		helper(0,0,size_i,size_j,matrix,ret);
		return ret;
    }
    void helper(int idx_i, int idx_j, int size_i, int size_j, vector<vector<int> >& matrix, vector<int>& ret){
    	if(size_i > 0 && size_j > 0){
    		int begin_i = idx_i;
	    	int end_i = idx_i + size_i;
	    	int begin_j = idx_j;
	    	int end_j = idx_j + size_j;
	    	for(int i = begin_j; i< end_j; i++)
	    		ret.push_back(matrix[begin_i][i]);
	        for(int i = begin_i+1; i < end_i; i++)
	        	ret.push_back(matrix[i][end_j-1]);
	        if(size_i != 1){
	   	        for(int i = end_j-2; i >= begin_j; i--)
	   		        ret.push_back(matrix[end_i-1][i]);
	        }
	        if(size_j != 1){
	   	        for(int i = end_i-2; i >= begin_i+1; i--)
	   		        ret.push_back(matrix[i][begin_j]);
	        }
	    	helper(idx_i+1,idx_j+1,size_i-2,size_j-2,matrix,ret);
    	}
    	else{
    		return;
    	}
    	

    }
};