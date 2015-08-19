class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int tmp = 0;
        for(int i = 0; i < nums.size(); i++)
            tmp ^= nums[i];
        int idx = tmp & (~(tmp-1));
        int ret1 = 0; int ret2 = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] & idx)
                ret1 ^= nums[i];
            else
                ret2 ^= nums[i];
        }
        vector<int> ret;
        ret.push_back(ret1);
        ret.push_back(ret2);
        return ret;
    }
};