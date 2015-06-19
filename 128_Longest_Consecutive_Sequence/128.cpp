#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	/* vector a would be huge in some bad case
		long long min = INT_MAX; long long max = INT_MIN;
		for(int i = 0; i < nums.size(); i++){
			if(nums[i] > max) max = nums[i];
			if(nums[i] < min) min = nums[i];
		}        
		vector<bool> a(max-min+1,false);
		for(int i = 0; i < nums.size(); i++)
			a[nums[i]-min] = true;

		int ret = 0; int cnt = 0;
		for(long long i = 0; i < max-min+1; i++){
			if(a[i]) cnt++;
			else{
				ret = ret > cnt ? ret : cnt;
				cnt = 0;
			}
		}
		return ret > cnt ? ret : cnt;
		*/
		set<int> a;
		for(int i = 0; i < nums.size(); i++)
			a.insert(nums[i]);
		set<int>::iterator it = a.begin(); 
		int prev = *it; it++;
		int ret = 0; int cnt = 1;
		while(it != a.end()){
			if(*it-prev==1) cnt++;
			else{
				ret = ret > cnt ? ret : cnt;
				cnt = 1;
			}
			prev = *it; it++;
		}
		return ret > cnt ? ret : cnt;
    }
};

int main(){
	Solution soln;
	int a[] = {100,4,200,1,3,2};
	vector<int> b(a,a+6);
	cout<<soln.longestConsecutive(b)<<endl;
}