class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // this solution fails when we have such test case:
        // nums = {100000,99999,99998,99997,...,1}, k = 10000
        if(nums.empty()) return vector<int>();
        vector<int> ret(nums.size()-k+1,INT_MIN);
        int max = INT_MIN; int maxidx = 0;
        for(int i = 0; i < k; i++){
            if(nums[i] > max){
                max = nums[i];
                maxidx = i;
            }
        }
        for(int i = 0; i < nums.size()-k+1; i++){
            if(i <= maxidx){
                if(nums[i+k-1] > max){
                    max = nums[i+k-1];
                    maxidx = i;
                    ret[i] = max;
                }else ret[i] = max;
            }else{
                max = nums[i]; maxidx = i;
                for(int j = i; j < i+k; j++){
                    if(nums[j] > max){
                        max = nums[j];
                        maxidx = j;
                    }
                }
                ret[i] = max;
            }
        }
        return ret;
    }
};