class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	int firstmiss = 1; int max = INT_MIN;
    	for(int i = 0; i < nums.size(); i++){
    		if(nums[i] > 0 && nums[i]==firstmiss)
    			firstmiss++;
    		if(nums[i] > max) max = nums[i];
    	}    
    	if(max < firstmiss) return firstmiss;
    	while(firstmiss < max){
    		bool ff = false;
	    	for(int i = nums.size()-1; i >=0 ;i--){
	    		if(nums[i] > 0 && nums[i]==firstmiss){
	    			ff = true;
    				firstmiss++;
    			}
	    	}
	    	if(!ff) return firstmiss;
    	}
    	return max+1;
    }
};