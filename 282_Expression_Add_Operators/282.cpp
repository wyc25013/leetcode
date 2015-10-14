class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> retset;
        helper(num, 0, target, 0, retset, "", 0);
        return retset;
    }
    
    void helper(string& num, int pos, int target, long curval, vector<string>& retset, string ret, long mul){
        if(pos == num.length()){
            if(curval == target)
                retset.push_back(ret);
            return;
        }
        for(int i = pos; i < num.length(); ++i){
            if(i != pos && num[pos] == '0') break;
            long tmp = stol(num.substr(pos,i-pos+1));
            if(pos == 0)
                helper(num, i+1, target, tmp, retset, ret + to_string(tmp), tmp);
            else{
                helper(num, i+1, target, curval+tmp, retset, ret + "+" + to_string(tmp), tmp);
                helper(num, i+1, target, curval-tmp, retset, ret + "-" + to_string(tmp), -tmp);
                helper(num, i+1, target, curval-mul+mul*tmp, retset, ret + "*" + to_string(tmp), mul*tmp);
            }
        }
    }
};