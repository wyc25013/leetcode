#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	if(numerator == 0) return "0";
    	long long numeratorl = (long long) numerator;
    	long long denominatorl = (long long) denominator;
    	string sign;
    	if(numeratorl*denominatorl < 0)
    		sign += "-";
		if(numeratorl < 0) numeratorl*=(-1);
		if(denominatorl < 0) denominatorl*=(-1);

		if(numeratorl > denominatorl){
			long long nn = numeratorl % denominatorl;
			long long N = numeratorl / denominatorl;

			return sign+to_string(N)+fractionToDecimal(nn,denominatorl).substr(1);
		}   
		if(numeratorl == denominatorl)
			return sign+"1";

		unordered_map<int,int> vi;
		string ret = "";

		while(numeratorl != 0){
			if(vi.find(numeratorl) != vi.end()){
				ret.insert(vi[numeratorl],"(");
				ret += ")";
				break;
			} else vi[numeratorl] = ret.length();
			string cur = to_string(numeratorl / denominatorl);
			numeratorl %= denominatorl;
			ret += cur;
			numeratorl *= 10;
		}
		if(ret[0] == '0') ret.insert(1,".");
		return sign+ret;
    }
};

int main(){
	Solution soln;
	cout<<soln.fractionToDecimal(-2147483648,1)<<endl;
	cout<<soln.fractionToDecimal(1,3)<<endl;
	cout<<soln.fractionToDecimal(1,17)<<endl;
	cout<<soln.fractionToDecimal(8,7)<<endl;
	cout<<soln.fractionToDecimal(2,11)<<endl;
}