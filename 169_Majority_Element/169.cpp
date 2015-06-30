#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	// solution 1
    	// hash
		int size = nums.size();
		if(size <= 2) return nums[0];
		int most = 0; int mostelem;
		unordered_map<int,int> m;
		for(int i = 0; i < size; i++){
			if(m.find(nums[i]) == m.end())
				m[nums[i]] = 1;
			else
				m[nums[i]]++;
			if(m[nums[i]] > most){
				most = m[nums[i]];
				mostelem = nums[i];
			}
			if(most > size/2)
				return mostelem;
		}
		return mostelem;
		/* solution 2
		 * sort
		sort(nums.begin(),nums.end());
		return nums[nums.size()/2];
		*/

		/* solution 3 
		 * Boyer-Moore Majority Vote Algorithm
		int j,count=0;
		j=nums[0];
		for(int i=0;i<nums.size();i++){
		    if(count==0) j=nums[i];
		    if(nums[i]==j) count++;
		    else count--;
		}
		return j;
		*/

		/* solution 
		 * bit manipulation
		int len = num.size();
        if (len < 3) return num[0];
        int half = len/2;
        int bit_ct[32];
        for (int i=0; i<32; ++i)  bit_ct[i] = 0;
        for (auto n:num){ // count the number of 1 occured on each bit position
            for (int i=0; i<32; ++i){
                if (n%2) ++bit_ct[i];
                n >>= 1;
            }
        }
        int ans = 0;
        for(int i=31; i>=0; --i){
            ans <<= 1;
            if (bit_ct[i]>half) ++ans;
        }
        return ans;
        */
    }
};

int main(){
	int a[] = {1,1,1,1,1,1,1,2,4,2,
			   7,3,3,1,3,2,1,6,3,1,
			   1,1};
	vector<int> b(a,a+22);
	Solution soln;
	cout<<soln.majorityElement(b)<<endl;
}