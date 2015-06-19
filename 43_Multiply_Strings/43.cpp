#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	if(num1 == "0" || num2 == "0")
    		return "0";
    	int len1 = num1.length();
    	int len2 = num2.length();
    	int val[len1][len2];
    	for(int i = len1-1; i >= 0 ; i--)
    		for(int j = len2-1; j >= 0; j--)
    			val[i][j] = (num1[i]-48)*(num2[j]-48);
    	string ret;
    	for(int i = 0; i < len1+len2; i++)
    		ret += "0";
    	int order = 0;
    	for(int i = len1+len2-1; i >= 0; i--){
    		int idx_i,idx_j;
    		if(i <= len1-1){
    			idx_i = i-1;
    			idx_j = 0;
    		}else{
    			idx_i = len1-1;
    			idx_j = i - (len1-1) - 1;
    		}
    		
    		int val_ij = 0;
    		while(idx_j <= len2-1 && idx_i >=0){
    			val_ij += val[idx_i][idx_j];
    			idx_i--;
    			idx_j++;
    		}
    		val_ij += order;
    		order = val_ij / 10;
    		val_ij %= 10;
    		ret[i] = (char)(val_ij+48);
       	}

    	if(ret[0] == '0')
    		return ret.substr(1,len1+len2-1);
    	else
    		return ret;
    }
};

int main(){
	Solution soln;
	cout<<soln.multiply("5618","2")<<endl;
}