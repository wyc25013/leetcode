#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
    	vector<vector<int> > retset;
    	int len = nums.size();
        sort(nums.begin(),nums.end());
    	for(int i = 0; i < len; i++){
    		int first = nums[i];
    		vector<int> ret;
    		if(i == 0 || nums[i] != nums[i-1]){
                vector<int> new_vec;
                newVector(new_vec,nums,i);
                ret.push_back(first);
                helper(new_vec, 0, len, ret, retset);
                ret.pop_back();
            }
    	}
    	return retset;
    }

    void helper(vector<int> choice, int pos, int size, vector<int>& ret, vector<vector<int> >& retset){
    	if(pos == size-1){
    		retset.push_back(ret);
    		return;
    	}
    	int len = choice.size();
    	for(int i = 0; i < len; i++){
            int next = choice[i];

            if(i == 0 || choice[i] != choice[i-1]){
                vector<int> new_vec;
                newVector(new_vec, choice, i);
                ret.push_back(next);
                helper(new_vec, pos+1, size, ret, retset);
                ret.pop_back(); 
            }
    	}
    }

    void newVector(vector<int>& new_vec, vector<int> origin, int pos){
    	for(int i = 0; i < origin.size(); i++){
    		if(i != pos)
    			new_vec.push_back(origin[i]);
    	}
    }
};

int main(){
	Solution soln;
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(3);
	vector<vector<int> > ret = soln.permute(a);
	int len = ret.size();
	for(int i = 0; i < len; i++){
		vector<int> tmp = ret.back();
		for(int j = 0; j < tmp.size(); j++){
			cout<<tmp[j]<<" ";
		}
		cout<<endl;
		ret.pop_back();
	}
}