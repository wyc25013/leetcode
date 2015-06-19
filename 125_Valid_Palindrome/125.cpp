#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        if(len < 2) return true;
        int head = 0;
        int tail = len-1;
        while(head < tail){
            char a = s[head]; char b = s[tail];
        	if((a>='A'&&a<='Z') || (a>='a'&&a<='z') || (a>='0'&&a<='9')){
        		if((b>='A'&&b<='Z') || (b>='a'&&b<= 'z') ||(b>='0'&&b<='9')){
        			if(a==b|| (abs(a-b)==32 &&a>'9'&&b>'9') ){
        			    head++;tail--;
        			}
        			else return false;
        		} else
        			tail--;
        	} else
        		head++;
        }

        return true;
    }
};