#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();

        vector<vector<int> > a(len1+1,vector<int>(len2+1,0));
        a[0][0] = 0; // a[i][j] means min# of operations to be done to
        			 // convert word1[0..i-1] to word2[0..j-1]
        for(int i = 1; i <= len1; i++)
        	a[i][0] = i;
        for(int i = 1; i <= len2; i++)
        	a[0][i] = i;

        for(int i = 1; i <= len1; i++){
        	for(int j = 1; j <= len2; j++){
        		if(word1[i-1]==word2[j-1])
        			a[i][j] = min(a[i-1][j-1],
        					1+min(a[i-1][j],a[i][j-1]));
        		else
        			a[i][j] = 1+min(a[i-1][j-1],
        					min(a[i-1][j],a[i][j-1]));
        	}
        }
        return a[len1][len2];
    }
};