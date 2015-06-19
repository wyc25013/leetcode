#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxProduct=INT_MIN;
        int product=1;
        for(int i=0;i<nums.size();++i){
            product*=nums[i];
            maxProduct=max(maxProduct,product);
            if(product==0) product=1;
        }
        product = 1;
        for(int i=nums.size()-1;i>=0;--i){
            product*=nums[i];
            maxProduct=max(maxProduct,product);
            if(product==0) product=1;
        }
        return maxProduct;
    }
};