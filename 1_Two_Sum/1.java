public class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> a = new HashMap<Integer,Integer>();
        int[] ret = new int[2];
        for(int i = 0; i < nums.length;i++){
            if(a.containsKey(target-nums[i])){
                ret[0] = a.get(target-nums[i]);
                ret[1] = i+1;
                return ret;
            }else
                a.put(nums[i],i+1);
        }
        return ret;
    }
}