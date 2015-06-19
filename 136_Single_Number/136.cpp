#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		for(int i = 0; i < nums.size(); i+=2){
			if(nums[i] != nums[i+1])
				return nums[i];
		}        
    }
};

/* faster solution using bit manipulation
 * a^b^a = b
 *      0010
 *  xor 1010
 * ----------
 *      1000
 *
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.empty()) return 0;
        int first = nums[0];
        for(int i = 1; i<nums.size();i++) {
            first = first ^ nums[i];
        }
        return first;
    }
};
*/