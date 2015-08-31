class Solution {
    unordered_map<int,string> um;
public:
    Solution(){
        um[1] = "One";      um[11] = "Eleven";      um[30] = "Thirty";
        um[2] = "Two";      um[12] = "Twelve";      um[40] = "Forty";
        um[3] = "Three";    um[13] = "Thirteen";    um[50] = "Fifty";
        um[4] = "Four";     um[14] = "Fourteen";    um[60] = "Sixty";
        um[5] = "Five";     um[15] = "Fifteen";     um[70] = "Seventy";
        um[6] = "Six";      um[16] = "Sixteen";     um[80] = "Eighty";
        um[7] = "Seven";    um[17] = "Seventeen";   um[90] = "Ninety";
        um[8] = "Eight";    um[18] = "Eighteen";    
        um[9] = "Nine";     um[19] = "Nineteen";
        um[10] = "Ten";     um[20] = "Twenty";
    }
    
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        string s;
        int tmp = num % 1000;
        num /= 1000;
        int hun = tmp / 100;
        int ten = (tmp % 100) / 10;
        int one = (tmp % 10);
        if(hun)
            s += um[hun] + " Hundred ";
        if(ten){
            if(ten ==1){
                s += um[ten*10+one];
            }else{
                s += um[ten*10] + " ";
            }
        }
        if(one && ten != 1)
            s += um[one];
            
        s = helper(num, 1) + " " + s;
        while(s[0] == ' ')
            s.erase(s.begin());
        if(s[s.length()-1] == ' ')
            s.erase(s.begin()+s.length()-1);
        return s;
    }
    
    string helper(int num, int thou_idx){
        string s;
        if(num == 0) return s;
        int tmp = num % 1000;
        num /= 1000;
        int hun = tmp / 100;
        int ten = (tmp % 100) / 10;
        int one = (tmp % 10);
        if(hun)
            s += um[hun] + " Hundred ";
        if(ten){
            if(ten ==1){
                s += um[ten*10+one];
            }else{
                s += um[ten*10] + " ";
            }
        }
        if(one && ten != 1)
            s += um[one];
        if(s[s.length()-1] == ' ')
            s.erase(s.begin()+s.length()-1);
        if(!s.empty()){
            if(thou_idx == 1){
                s += " Thousand ";
            }else if(thou_idx == 2){
                s += " Million ";
            }else if(thou_idx == 3){
                s += " Billion ";
            }
        }
 
        s = helper(num, thou_idx+1) + " " +s;
        while(s[0] == ' ')
            s.erase(s.begin());
        if(s[s.length()-1] == ' ')
            s.erase(s.begin()+s.length()-1);
        return s;   
    }
};