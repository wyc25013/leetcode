#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
		int len = s.length();
		// cut all space and sign
		int start = 0;
		while(s[start]==' ')
			start++;
		if(start==len) return false;
		int cntsign = 0;
		while(s[start]=='+' || s[start]=='-'){
			start++; cntsign++;
		}
		if(cntsign > 1) return false;
		int end = len-1;
		while(s[end]==' ')
			end--;
		if(end == -1) return false;

		int cntdot = 0;
		int cnte = 0;
		cntsign = 0;
		for(int i = start; i <= end; i++){
			if(s[i]==' ') return false;
			else if(s[i]=='.'){
			    if(i==start&&i==end) return false;
				if(cntdot==0) cntdot++;
				else return false;
				if(cnte==1) return false;
			}
			else if(s[i]=='e'){
				if(i==start) return false;
				if(s[i-1]=='+'||s[i-1]=='-') 
				    return false;
				if(cnte==0) cnte++;
				else return false;
				if(i==end) return false;
				if(s[i-1]=='.'){
				    if(i-1==start) return false;
				    else{
				        if(s[i-2] <'0'||s[i-2]>'9')
				            return false;
				    }
				}
			}
			else if(s[i]=='-'||s[i]=='+'){
				if(s[i-1]!='e') return false;
				if(cntsign==0) cntsign++;
				else return false;
				if(i==end) return false;
			}
			else if((s[i] < '0' || s[i] > '9') &&
			       s[i]!='-'&&s[i]!='+'&&s[i]!='e'&&s[i]!='.')
				return false;
				
		}  
		return true;
    }
};