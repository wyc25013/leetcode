class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /* non-zero elements should maintain order
        int lastZeroIdx = nums.size()-1;
        while(nums[lastZeroIdx] == 0)
            --lastZeroIdx;
        for(int i = 0; i < lastZeroIdx; ++i){
            if(nums[i] != 0) continue;
            else{
                nums[i] = nums[lastZeroIdx];
                nums[lastZeroIdx] = 0;
                --lastZeroIdx;
            }
        }
        */
        int cur = 0;
        while(cur < nums.size() && nums[cur] != 0)
            ++cur;
        for(int i = cur; i < nums.size(); ++i){
            if(nums[i] == 0) continue;
            else{
                nums[cur] = nums[i];
                nums[i] = 0;
                ++cur;
            }
        }
    }
};