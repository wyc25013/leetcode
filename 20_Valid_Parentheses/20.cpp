#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) { 
        if (s.length()%2)
        	return false;
       
       	int circle = 0;
       	int square = 0;
       	int flower = 0;
       	stack<char> inner;

        int result = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
        	if (s[i] == '[') {
        		square+= -1;
        		inner.push('s');
        	}
			else if (s[i] == '{') {
				flower+= -1;
				inner.push('f');
			}
			else if (s[i] == '(') {
				circle+= -1;
				inner.push('c');
			}
			else if (s[i] == ']') {
				if (inner.empty() || inner.top() != 's')
					return false;
				else {
					square+= 1;
					inner.pop();
				}
			}
			else if (s[i] == '}') {
				if (inner.empty() || inner.top() != 'f')
					return false;
				else {
					flower+= 1;
					inner.pop();
				}
			}
			else if (s[i] == ')') {
				if (inner.empty() || inner.top() != 'c' )
					return false;
				else {
					circle+= 1;
					inner.pop();
				}
			}
        	
        }
        if(inner.size() || circle || flower || square)
        	return false;
        return true;
    }
};
//sth is redundent. modification is needed... but the point is stack datastructure...
int main(){
	Solution soln;
	cout << soln.isValid("[][][]{}{}{}{}()()[]") <<endl;
	cout << soln.isValid("[](){[]}") <<endl;
	cout << soln.isValid("[(])") <<endl;
	cout << soln.isValid("]})[{(") <<endl;
	return 0;
}