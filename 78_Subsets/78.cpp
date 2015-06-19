#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
		vector<vector<int> > retset;
		vector<int> empty;
		retset.push_back(empty);
		retset.push_back(nums);

		int len = nums.size();
		if(len == 1)
			return retset;
		for(int i = 1; i <= len-1;i++){
			combine(i,retset,nums);
		}
		return retset;

    }

    void combine(int k,vector<vector<int> >& retset,vector<int>& nums) {
		vector<int> ret;
		int n = nums.size();
		for(int i = 0; i <= n-k; i++){
			ret.push_back(nums[i]);
			helper(1,i,n,k,retset,ret,nums);
			ret.pop_back();
		}        
    }

    void helper(int pos, int i, int n, int k, vector<vector<int> >& retset,vector<int>& ret,vector<int>& nums){
    	if(pos == k){
    		retset.push_back(ret);
    		return;
    	}else{
    		for(int j = i+1; j <= n-k+pos; j++){
    			ret.push_back(nums[j]);
    			helper(pos+1,j,n,k,retset,ret,nums);
    			ret.pop_back();
    		}
    	}
    }
};

int main(){
	int a[]={3,2,1};
	vector<int> b(a,a+sizeof(a)/sizeof(int));
	Solution soln;
	vector<vector<int> > ret = soln.subsets(b);
	while(ret.size()){
		vector<int> tmp = ret.back();
		while(tmp.size()){
			cout<<tmp.back()<<" ";
			tmp.pop_back();
		}
		cout<<endl;
		ret.pop_back();
	}
}