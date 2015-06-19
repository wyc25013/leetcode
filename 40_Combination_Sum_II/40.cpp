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
					if(i > 0 && candidates[i] == candidates[i-1]){
						int count_candidate = 1;
						int j = i-1;
						while(j >= 0){
							if(candidates[j] == candidates[i]){
								count_candidate++;
								j--;
							}
							else
								break;
						}
						int count_ret = 0;
						for(int k = 0; k < ret.size(); k++){
							if(ret[k] == candidates[i]){
								count_ret++;
							} else if (ret[k] > candidates[i]){
								break;
							}
						}
						if(count_ret + 1 == count_candidate){
							ret.push_back(candidates[i]);
							helper(candidates,size,i+1,target-candidates[i],ret,retset);
							ret.pop_back();
						} else {
							continue;
						}
					} else {
						ret.push_back(candidates[i]);
						helper(candidates,size,i+1,target-candidates[i],ret,retset);
						ret.pop_back();
					}
				} else {
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
	a.push_back(10);
	a.push_back(1);
	a.push_back(2);
	a.push_back(7);
	a.push_back(6);
	a.push_back(1);
	a.push_back(5);
	Solution soln;
	vector<vector<int> > b = soln.combinationSum(a,8);
	while(b.size()){
		vector<int> tmp = b.back();
		for(int i = 0; i < tmp.size(); i++){
			cout << tmp[i] << " ";
		}
		cout<<endl;
		b.pop_back();
	}
}