class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        int start = 0; int end = 0;
        vector<string> ret;
        if(len==0) return ret;
        if(len==1){
            ret.push_back(to_string(nums[0]));
            return ret;
        }
        for(int i = 1; i < len; i++){
            if(nums[i]-nums[i-1]==1){
                end++;
            }else{
                if(start==end)
                    ret.push_back(to_string(nums[start]));
                else
                    ret.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
                start = i;
                end = i;
            }
        }
        if(start==end)
            ret.push_back(to_string(nums[start]));
        else
            ret.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
        return ret;
    }
};