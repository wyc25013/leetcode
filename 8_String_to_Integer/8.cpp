#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int atoi1(string str) {
		int len = str.length();
		long long result = 0;
		bool sign = 1;
		bool ifsigned = 0;
		int count = 0;

		if (!len)
			return 0;
		
		while (str[count] == 32) {
			count++;
		}
        
        if (count == len)
            return 0;
        
		for (int i = count; i < len; i++){
			if (str[i] < 58 && str[i] > 47){
				result = result*10 + str[i] - 48;
				if (result > INT_MAX)
				    break;
			}
			else if (str[i] == 45 ||str[i] == 43){
				if (ifsigned)
					return 0;
				else{
					if(str[i] == 45){
						sign = 0;
						ifsigned = 1;
					}
					else if (str[i] == 43){
						sign = 1;
						ifsigned = 1;
					}
				}
			}
			else
			    break;
		} 

		if (!ifsigned)
		    sign = 1;
		
        if (result > INT_MAX)
            return (sign == 1 ? INT_MAX : INT_MIN);
        else
		    return (sign == 1 ? result : (-1)*result);
	}
};

int main(){
	string s1 = "-12a46";
	string s2 = "2147483648";
	Solution soln;
	cout<<soln.atoi1(s1)<<" "<<soln.atoi1(s2)<<endl;
	return 0;
}
// simple approach using stringstream
/*
class Solution {
public:
	int result;
    stringstream strStream;
    strStream<<str;
    strStream>>result;
    return result;
}
*/