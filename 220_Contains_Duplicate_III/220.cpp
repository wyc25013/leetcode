#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k*t < 0) return false;
        if(k==0) return false;
        set<int> window;
        int toberm = 0;
        int len = nums.size();
        if(len <= 1) return false;
        for(int i = 0; i < len; i++){
            if(window.find(nums[i]) != window.end()) return true;
            else{
                // key point in this problem that
                // you needn't traversal the whole set
                // but only one element in the set
                set<int>::iterator it = window.lower_bound(nums[i]-t);
                if(it != window.end() && abs((*it) - nums[i]) <= t)
                    return true;
            }
            if(window.size() >= k) window.erase(nums[toberm++]);
            window.insert(nums[i]);
        }
        return false;
    }    
};