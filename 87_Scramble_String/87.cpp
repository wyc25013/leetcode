#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
    	int len = s1.length();
    	if(s1==s2) return true;
    	/* misunderstand this problem
    	if(len % 2 == 0)
    		return (isScramble(s1.substr(len/2),s2.substr(len/2))
    		&&isScramble(s1.substr(0,len/2),s2.substr(0,len/2))) 
    		|| (isScramble(s1.substr(len/2),s2.substr(0,len/2))
    		&&isScramble(s1.substr(0,len/2),s2.substr(len/2)));
    	else
    		return (isScramble(s1.substr(len/2),s2.substr(len/2))
    		&&isScramble(s1.substr(0,len/2),s2.substr(0,len/2))) 
    		|| (isScramble(s1.substr(len/2),s2.substr(0,len/2+1))
    		&&isScramble(s1.substr(0,len/2),s2.substr(len/2+1)))
    		|| (isScramble(s1.substr(0,len/2+1),s2.substr(0,len/2+1))
    		&&isScramble(s1.substr(len/2+1),s2.substr(len/2+1)))
    		||(isScramble(s1.substr(0,len/2+1),s2.substr(len/2))
    		&&isScramble(s1.substr(len/2+1),s2.substr(0,len/2)));
    	*/
		
		// see whether component of string is the same
		// this can reduce the time cost by a lot
		// cuz it makes backtracking as soon as possible
		int count[26] = {0};
        for(int i=0; i<len; i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(count[i]!=0)
                return false;
        }
    	for(int i = 1; i < len; i++){
    		if(isScramble(s1.substr(0,i),s2.substr(0,i)) 
    		&& isScramble(s1.substr(i),s2.substr(i)))
    			return true;
    		if(isScramble(s1.substr(0,i),s2.substr(len-i)) 
    		&& isScramble(s1.substr(i),s2.substr(0,len-i)))
    			return true;
    	}
		return false;
		
		// though solved recursively, this problem can still be
		// improved by dp. actually we can cache something like
		// s1.substr(0,i)+"*"+s2.substr(0,i) in a hash table 
    }
};

int main(){
	Solution soln;
	cout<<soln.isScramble("abc","cab")<<endl;
}