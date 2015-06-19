#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
    	int len = nums.size();
    	if(len < 2) return 0;
    	set<int> a;
		for(int i = 0; i < len; i++)
			a.insert(nums[i]);
		set<int>::iterator it = a.begin(); 
		int prev = *it; it++;
		int ret = 0; int gap = 1;
		while(it != a.end()){
			if(*it-prev != 1) {
				gap = *it - prev;
				ret = ret > gap ? ret : gap;
			}
			prev = *it; it++;
		}
		return ret; 
		/* better solution 
		/* put them in buckets
		const int n = nums.size();
        if(n<=1) return 0;
        int maxE = *max_element(nums.begin(),nums.end());
        int minE = *min_element(nums.begin(),nums.end());
        double len = double(maxE-minE)/double(n-1);
        vector<int> maxA(n,INT_MIN);
        vector<int> minA(n,INT_MAX);
        for(int i=0; i<n; i++) {
            int index = (nums[i]-minE)/len;
            maxA[index] = max(maxA[index],nums[i]);
            minA[index] = min(minA[index],nums[i]);
        }
        int gap = 0, prev = maxA[0];
        for(int i=1; i<n; i++) {
            if(minA[i]==INT_MAX) continue;  // skip the empty interval
            gap = max(gap,minA[i]-prev);
            prev = maxA[i];
        }
        return gap;
        */
    }
};