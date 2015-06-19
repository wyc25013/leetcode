#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int calculate(string s) {
  		int len = s.length();
  		stack<int> a; 
  		int sign = 1; int flag = 1;
  		for (int i = 0; i < len;){
  			if(s[i] == ' ') i++;
  			else if(s[i] == '+'){
  				sign = 1;
  				i++;
  			} else if(s[i] == '-'){
  				sign = -1;
  				i++;
  			} else if(s[i] == '('){
  				flag = 1;
  				i++;
  			} else if(s[i] == ')'){
  				int t1 = a.top(); a.pop();
  				int s1 = a.top(); a.pop();
  				if(!a.empty()){
  				    int t2 = a.top(); a.pop();
  				    a.push(s1*t1+t2);
  				} else
  				    a.push(s1*t1);
  				i++;
  			}else{
  				int d = 0;
	  			while(s[i] >= 48 && s[i] <= 57){
	  				d *= 10;
	  				d += s[i]-48;
	  				i++;
	  			}
	  			if(flag){
	  				a.push(sign);
	  				a.push(d);
	  				flag = 0;
	  			}else{
	  				int t = a.top(); a.pop();
	  				a.push(t+sign*d);
	  			}
  			}
  		}    
  		return a.top(); 
    }
};

int main(){
	string s = "10+6 +( 5- (1 - 1)+1)";
	Solution soln;
	cout << soln.calculate(s)<<endl;
}