#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;
/*
int AtoI(char x) {
	if (x == 'I')
		return 1;
	else if (x == 'V')
		return 5;
	else if (x == 'X')
		return 10;
	else if (x == 'L')
		return 50;
	else if (x == 'C')
		return 100;
	else if (x == 'D')
		return 500;
	else if (x == 'M')
		return 1000;
	else
		return 0;
}
*/

//what a ugly code....
/*
class Solution {
public:
	string intToRoman(int num) {
		string result;
		while(num){
			if(num < 1000){
				if (num < 500) {
					if(num >= 400) {
						result+= "CD";
						num%= 400;
					} else {
						if(num < 100){
							if(num < 50) {
								if(num < 10) {
									if(num < 5){
										if(num == 4){
											result+= "IV";
											num%= 4;
										}
										else {
											for(;num > 0;num--)
												result+= "I";
										}
									} else {
										if(num == 9){
											result+= "IX";
											num%= 9;
										}
										else {
											result+= "V";
											num%= 5;
										}
									}
								} else {
									if(num < 40){
										int a = num / 10;
										for(;a > 0;a--)
											result+= "X";
										num%= 10;
									} else {
										result+= "XL";
										num%= 40;
									}
								}
							} else {
								if(num < 90) {
									result+= "L";
									num%= 50;
								} else {
									result+= "XC";
									num%= 90;
								}
							}
						} else {
							int a = num / 100;
							for(;a > 0; a--)
								result+= "C";
							num%= 100;
						}
					}
				} else {
					if(num >= 900) {
						result+= "CM";
						num%= 900;
					} else {
						result+= "D";
						num%= 500;
					}
				}
			} else {
				int a = num / 1000;
				for(;a > 0; a--)
					result+= "M";
				num%= 1000; 
			}
		}
		return result;
	}
};
/* other guy's beautiful code...
class Solution {
public:
    string intToRoman(int num) {                
        for (int i = 0; i < int_dict.size(); i++) {
            if (int_dict[i] <= num)
                return roman_dict[i] + intToRoman(num - int_dict[i]);
        }
        return "";
    }
private:
    vector<int> int_dict {
    	1000, 900, 500, 400, 100,
        90, 50, 40, 10, 9, 5, 4, 1
    };
    vector<string> roman_dict {
    	"M", "CM", "D", "CD", 
        "C", "XC", "L", "XL", "X", 
        "IX", "V", "IV", "I"
    };
};
*/
//try recursive solution

class Solution {
public:
	//Solution()  {div[13] = 1000;}
	string intToRoman(int num) {  
		string result;
		for (int i = 0; i < 13; i++) {
			if(div[i] <= num) {
				int tmp = num / div[i];
				for (; tmp > 0; tmp--) {
					result+= roman[i];
				}
				num%= div[i];
				return result + intToRoman(num);
			}
		}
		return "";
	}

private:
	//enum { size = 13};
	int div[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
	string roman[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	//int div[13];
	//string roman[13];
};

int main(){
	Solution soln;
	cout << soln.intToRoman(419) <<endl;
	cout << soln.intToRoman(320) <<endl;
	cout << soln.intToRoman(1992) <<endl;
	cout << soln.intToRoman(73) <<endl;
	return 0;
}