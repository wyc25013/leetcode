#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//customised sort
class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	int len = nums.size();
    	if(!len) return "";
    	vector<string> snums;
    	for(int i = 0; i < len; i++)
    		snums.push_back(to_string(nums[i]));
    	sort(snums.begin(),snums.end(),
    	     [](string m, string n){ return m+n > n+m;}
    	     );
    	string ret;
    	for(int i = 0; i < len; i++)
    		ret += snums[i];
        if(ret[0] == '0') return "0";
    	return ret;
    }
};

int main(){
	int a[] = {121,12};
	vector<int> b(a,a+2);
	Solution soln;
	cout<<soln.largestNumber(b)<<endl;
}