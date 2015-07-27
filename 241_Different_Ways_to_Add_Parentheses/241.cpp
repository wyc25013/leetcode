class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> nums; vector<char> ops;
        for(int i = 0; i < input.size(); ){
            if(input[i] >= '0' && input[i] <= '9'){
                int tmp = 0;
                while(input[i] >= '0' && input[i] <= '9'){
                    tmp *= 10;
                    tmp += (input[i]-'0');
                    i++;
                }
                nums.push_back(tmp);
            }else{
                ops.push_back(input[i]);
                i++;
            }
        }
        
        int len = nums.size();
        if(len==1) return nums;
        vector<int> ret;
        for(int i = 1; i <= len-1; i++){
            vector<int> p1 = helper(nums,0,i-1,ops);
            char op = ops[i-1];
            vector<int> p2 = helper(nums,i,len-1,ops);
            for(int i1 = 0; i1 < p1.size(); i1++){
                for(int i2 = 0; i2 < p2.size(); i2++){
                    if(op == '+')
                        ret.push_back(p1[i1]+p2[i2]);
                    else if(op == '-')
                        ret.push_back(p1[i1]-p2[i2]);
                    else
                        ret.push_back(p1[i1]*p2[i2]);
                }
            }
        }
        return ret;
    }
    
    vector<int> helper(vector<int>& nums,int s,int e,vector<char>& ops) {
        if(s == e) return vector<int>(1,nums[s]);
        vector<int> ret; int len = e-s+1;
        for(int i = 1; i <= len-1; i++){
            vector<int> p1 = helper(nums,s,s+i-1,ops);
            char op = ops[s+i-1];
            vector<int> p2 = helper(nums,s+i,s+len-1,ops);
            for(int i1 = 0; i1 < p1.size(); i1++){
                for(int i2 = 0; i2 < p2.size(); i2++){
                    if(op == '+')
                        ret.push_back(p1[i1]+p2[i2]);
                    else if(op == '-')
                        ret.push_back(p1[i1]-p2[i2]);
                    else
                        ret.push_back(p1[i1]*p2[i2]);
                }
            }
        }
        return ret;
    }
};