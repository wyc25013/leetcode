#include <iostream>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
    	string ret;
    	n--;
        while(n >= 0){
        	int a = n / 26;
        	int b = n % 26;
        	ret = (char)(b+65) + ret;
        	n = a-1;
        }
        return ret;
    }
};

int main(){
	Solution soln;
	cout<<soln.convertToTitle(27)<<endl;
	cout<<soln.convertToTitle(13)<<endl;
	cout<<soln.convertToTitle(1)<<endl;
	cout<<soln.convertToTitle(55)<<endl;
	cout<<soln.convertToTitle(88)<<endl;
}