#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int len1 = s1.length();
    	int len2 = s2.length();
    	int len3 = s3.length();
    	if(len1 + len2 != len3) return false;
    	/* TLE
    	vector<int> a(26,0);
    	for(int i = 0; i < len1; i++)
    		a[s1[i]-'a']++;
    	for(int i = 0; i < len2; i++)
    		a[s2[i]-'a']++;
    	for(int i = 0; i < len3; i++)
    		a[s3[i]-'a']--;
    	for(int i = 0; i < 26; i++)
    		if(a[i] != 0) return false;
    	if(s1.empty()) return s2==s3;
    	if(s2.empty()) return s1==s3;
    	if(s3[0] == s1[0] && s3[0] != s2[0])
    		return isInterleave(s1.substr(1),s2,s3.substr(1));
    	else if(s3[0] != s1[0] && s3[0] == s2[0])
    		return isInterleave(s1,s2.substr(1),s3.substr(1));
    	else if(s3[0] == s1[0] && s3[0] == s2[0])
    		return isInterleave(s1.substr(1),s2,s3.substr(1)) 
    			|| isInterleave(s1,s2.substr(1),s3.substr(1));
    	else return false;
    	*/

    	// dp solution
    	// a[i][j] ==> s1[0..i-1] and s2[0..j-1] matches 
    	// s3[0..i+j-1]
    	vector<vector<bool> > a(len1+1,vector<bool>(len2+1,false));
    	a[0][0] = true;
    	for(int i = 1; i <= len1; i++)
    		a[i][0] = a[i-1][0] && s1[i-1]==s3[i-1];
    	for(int i = 1; i <= len2; i++)
    		a[0][i] = a[0][i-1] && s2[i-1]==s3[i-1];

    	for(int i = 1; i <= len1; i++){
    		for(int j = 1; j <= len2; j++){
    			a[i][j] = (a[i-1][j] && s3[i+j-1]==s1[i-1])
    					||(a[i][j-1] && s3[i+j-1]==s2[j-1]);
    		}
    	}
    	return a[len1][len2];
    }
};

int main(){
	Solution soln;
	cout<<soln.isInterleave("aabcc","dbbca","aadbbcbcac")<<endl;
	cout<<soln.isInterleave("aabcc","dbbca","aadbbbaccc")<<endl;
}