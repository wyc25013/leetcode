#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > retset;
		vector<int> ret;
		for(int i = 1; i <= n-k+1; i++){
			ret.push_back(i);
			helper(1,i,n,k,retset,ret);
			ret.pop_back();
		}        
		return retset;
    }

    void helper(int pos, int i, int n, int k, vector<vector<int> >& retset,vector<int>& ret){
    	if(pos == k){
    		retset.push_back(ret);
    		return;
    	}else{
    		for(int j = i+1; j <= n-k+1+pos; j++){
    			ret.push_back(j);
    			helper(pos+1,j,n,k,retset,ret);
    			ret.pop_back();
    		}
    	}
    }
};

int main(){
	Solution soln;
	vector<vector<int> > ret = soln.combine(13,13);
	while(ret.size()){
		vector<int> tmp = ret.back();
		for(int i = 0; i < 13; i++){
			cout<<tmp[i]<<" ";
		}
		cout<<endl;
		ret.pop_back();
	}
}