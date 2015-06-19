#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        for(int i = s.length()-1; s[i] == ' '; i--){
            s.pop_back();
        }
		int pos = s.find_last_of(" ");
		if(pos == string::npos)
		    return s.length();
		return s.length() - 1 - pos;

    }
};

int main(){
	string s1 = "world   ";
	string s2 = " world   ";
	string s3 = "hello world   ";
	string s4 = "hello world";
	Solution soln;
	cout<<soln.lengthOfLastWord(s1)<<endl;
	cout<<soln.lengthOfLastWord(s2)<<endl;
	cout<<soln.lengthOfLastWord(s3)<<endl;
	cout<<soln.lengthOfLastWord(s4)<<endl;
}