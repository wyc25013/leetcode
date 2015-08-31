class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size()+1;
        int b = 0;
        if(len%4 == 0){
            // do nothing
        }else{
            if(len%4 == 1){
                b ^= len;
                b ^= len+1;
                b ^= len+2;
            }else if(len%4 == 2){
                b ^= len;
                b ^= len+1;
            }else{  //len%4 ==3
                b ^= len;
            }
        }
        for(int i = 0; i < len-1; i++)
            b ^= nums[i];
        return b;
        
    }
};