#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> ret(rowIndex+1,1);
    	if(!rowIndex) return ret; 
		helper(1,rowIndex,ret);
		return ret;        
    }

    void helper(int level, int row, vector<int>& ret){
    	if(level > row) return;
        int tmp = ret[0];
    	for(int i = 1; i < level; i++){
    	    int a = ret[i];
    	    ret[i] += tmp;
    	    tmp = a;
    	}
    	helper(level+1,row,ret);
    }
};