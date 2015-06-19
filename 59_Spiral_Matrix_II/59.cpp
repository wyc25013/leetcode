#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> > ret;
    	for(int i = 0; i < n; i++){
    		vector<int> a(n,0);
    		ret.push_back(a);
    	}
		helper(1,0,n,ret);
		return ret;
    }

    void helper(int start, int layer, int size, vector<vector<int> >& ret){
    	if(start <= size*size){
    		for(int i = layer; i <= size-1-layer; start++,i++)
    			ret[layer][i] = start;
    		for(int i = layer+1; i <= size-1-layer; start++,i++)
    			ret[i][size-1-layer] = start;
    		for(int i = size-2-layer; i >= layer; start++,i--)
    			ret[size-1-layer][i] = start;
    		for(int i = size-2-layer; i >= layer+1; start++,i--)
    			ret[i][layer] = start;
    		helper(start,layer+1,size,ret);
    	}
    }
};

int main(){
	Solution soln;
	vector<vector<int> > ret = soln.generateMatrix(1);
}