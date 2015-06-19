#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
		vector<vector<int> > retset;
		sort(nums.begin(),nums.end());
		int len = nums.size();
		vector<int> empty;
		retset.push_back(empty);
		if(len == 0)
			return retset;
		if(len == 1){
			vector<int> a;
			a.push_back(nums[0]);
			retset.push_back(a);
			return retset;
		}

		for(int i = 1; i <= len; i++){
		//	for(int j = 0; j < len; j++){
				vector<int> tmp;
				helper(0, i, 0, nums, tmp, retset);
		//	}
		}

		return retset;
    }

    void helper(int pos_subset, int subsize, int pos_nums, vector<int>& nums, vector<int>& subset, vector<vector<int> >& retset){
    	if(pos_subset == subsize){
    		retset.push_back(subset);
    		return;
    	}else{
    		for(int j = pos_nums; j < nums.size(); j++){
    			int a = nums[j];
	    		int cnt_nums = 0;
	    		int cnt_subset = 0;
	    		for(int i = j; i>=0 && a == nums[i]; i--){
	    			cnt_nums++;
	    		}
	    		for(int i = pos_subset; i-1>=0 && subset[i-1] == a; i--){
	    			cnt_subset++;
	    		}

	    		if(cnt_subset+1 == cnt_nums){
	    			subset.push_back(a);
	    			helper(pos_subset+1,subsize,j+1,nums,subset,retset);
	    			subset.pop_back();
	    		}

	    	//	while(nums[j] == nums[j+1])
	    	//		j++;
    		}
    	}
    }
};

int main(){
	int a[] = {1,2,2};
	vector<int> b(a,a+3);
	Solution soln;
	vector<vector<int> > c = soln.subsetsWithDup(b);
	while(c.size()){
		vector<int> tmp = c.back();
		while(tmp.size()){
			cout<<tmp.back()<<" ";
			tmp.pop_back();
		}
		cout<<endl;
		c.pop_back();
	}
}