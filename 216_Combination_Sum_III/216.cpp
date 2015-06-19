#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > retset;
        vector<int> ret;
        for(int i = 1; i <= 9; i++){
        	ret.push_back(i);
        	helper(n-i,ret,retset,k-1,i+1);
        	ret.pop_back();
        }
        return retset;
    }	

    void helper(int n, vector<int>& ret, vector<vector<int> >& retset, int k, int pos){
    	if(k==0 && n==0){
    		retset.push_back(ret);
    		return;
    	} else if(k==0 && n < 0)
    		return;

    	for(int i = pos; i <= 9; i++){
    		ret.push_back(i);
    		helper(n-i,ret,retset,k-1,i+1);
    		ret.pop_back();
    	}
    }
};

int main(){
	Solution soln;
	vector<vector<int> > a = soln.combinationSum3(3,9);
	while(!a.empty()){
		vector<int> tmp = a.back();
		for(int i = 0; i < 3; i++){
			cout<<tmp[i]<<" ";
		}
		cout<<endl;
		a.pop_back();
	}
}