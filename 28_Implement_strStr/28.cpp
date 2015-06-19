#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(char *haystack, char *needle) {
    	char* np = needle;
    	char* hp = haystack;
    	int nlen = 0;
    	int hlen = 0;
    	while(*np != '\0') {
    		nlen++;
    		np++;
    	}
    	while(*hp != '\0') {
    		hlen++;
    		hp++;
    	}

    	if(nlen > hlen)
    		return -1;
    	int dif = hlen - nlen + 1;
    	hp = haystack;
    	while(dif > 0){
    		np = needle;
    		char* tmp = hp;
    		while(*np != '\0'){
    			if(*np != *tmp)
    				break;
    			np++;
    			tmp++; 
    		}
    		if(*np == '\0')
    			return hp - haystack;
    		hp++;
    		dif--;
    	}
    	return -1;
    }
};

int main () {
	Solution soln;
	string haystack = "mississippi";
	string needle = "issip";
	int i = soln.strStr(&haystack[0], &needle[0]);
	cout << i << endl;
}