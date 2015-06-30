class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        int len = nums.size();
        if(!len) return ret;
        int can1 = nums[0]; int can2;
        int cnt1 = 1; int cnt2 = 0;
        for(int i = 1; i < len; i++){
            if(nums[i]==can1)
                cnt1++;
            else if(nums[i]==can2)
                cnt2++;
            else if(cnt1==0){
                can1 = nums[i];
                cnt1++;
            }else if(cnt2==0){
                can2 = nums[i];
                cnt2++;
            }else{   //cnt1,2>0 && nums[i]!=can1,2
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0; cnt2 = 0;
        for(int i = 0; i < len;i++){
            if(nums[i]==can1) cnt1++;
            else if(nums[i]==can2) cnt2++;
        }
        if(cnt1>len/3) ret.push_back(can1);
        if(cnt2>len/3) ret.push_back(can2);
        return ret;
    }
};

// this solution can be generalised from 2 to k