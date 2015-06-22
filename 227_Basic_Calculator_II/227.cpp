class Solution {
public:
    int calculate(string s) {
        int len = s.length();
        stack<int> a; int sign = 1;
        for(int i = 0; i < len;){
            if(s[i]==' ') i++;
            else if(s[i]>= '0' && s[i] <= '9'){
                int d = 0;
                while(i < len && s[i]>='0'&&s[i]<='9'){
                    d = d*10+s[i]-48;
                    i++;
                }
                a.push(sign*d);
            }else if(s[i]=='+' || s[i]=='-'){
                if(s[i]=='+') sign = 1;
                else sign = -1;
                i++;
            }else if(s[i]=='*'||s[i]=='/'){
                if(s[i]=='*'){
                    int m = a.top();
                    i++;
                    while(s[i]==' ') i++;
                    a.pop();
                    int d = 0;
                    while(i < len && s[i]>='0'&&s[i]<='9'){
                        d = d*10+s[i]-48;
                        i++;
                    }
                    a.push(m*d);
                }else{
                    int m = a.top();
                    i++;
                    while(s[i]==' ') i++;
                    a.pop();
                    int d = 0;
                    while(i < len && s[i]>='0'&&s[i]<='9'){
                        d = d*10+s[i]-48;
                        i++;
                    }
                    a.push(m/d);
                }
            }
        }
        int ret = 0;
        while(!a.empty()){
            ret += a.top();
            a.pop();
        }
        return ret;
    }
};