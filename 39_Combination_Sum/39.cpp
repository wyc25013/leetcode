#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void helper(vector<int> &candidates,int size,int pos,int target,vector<int>& ret,vector<vector<int> >& retset){
		if(target == 0){
			retset.push_back(ret);
			return;
		}
		else{
			for(int i = pos; i < size; i++){
				if(target - candidates[i] >= 0){ 
				    if(i > 0 && candidates[i] == candidates[i-1])
				        continue;
					ret.push_back(candidates[i]);
					helper(candidates,size,i,target-candidates[i],ret,retset);
					ret.pop_back();
				}else{
					break;
				}
			}
		}
	}
	
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
    	vector<vector<int> > retset;
		vector<int> ret;
		int size = candidates.size();
		sort(candidates.begin(),candidates.end());
		helper(candidates,size,0,target,ret,retset);
		return retset;
    }
};

int main(){
	vector<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(6);
	a.push_back(7);
	Solution soln;
	vector<vector<int> > b = soln.combinationSum(a,7);
	while(b.size()){
		vector<int> tmp = b.back();
		for(int i = 0; i < tmp.size(); i++){
			cout << tmp[i] << " ";
		}
		cout<<endl;
		b.pop_back();
	}
}