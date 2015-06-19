#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
   		while(a.length() > b.length())
   			b = "0"+b;
		while(a.length() < b.length())
			a = "0"+a;
		int len = a.length();
		int proceed = 0;
		for(int i = len-1; i >= 0; i--){
			int ia = a[i]-48;
			int ib = b[i]-48;
			if(ia+ib+proceed >= 2){
				if(ia+ib+proceed == 3){
					a[i] = '1';
				} else {
					a[i] = '0';
				}
				proceed = 1; 
			}else{
//				cout<<ia+ib<<endl;
				a[i] = (ia+48+ib+proceed);
//				cout<<a[i]<<endl;
				proceed = 0;
			}
		}        

		if(proceed == 1){
			a = "1"+a;
			return a;
		}else
			return a;
    }
};

int main(){
	Solution soln;
	string a = "111";
	string b = "10";
	cout<<soln.addBinary(a,b)<<endl;
}