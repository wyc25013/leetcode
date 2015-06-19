#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    	/* recursive solution
        if(p.empty()) return s.empty();
        if(p[0] == '*')
        	return isMatch(s,p.substr(1)) || (!s.empty() && isMatch(s.substr(1),p));
        else
        	return !s.empty() && (p[0]==s[0] || p[0]=='?') && isMatch(s.substr(1),p.substr(1)); 
		*/
        int lens = s.length(); int lenp = p.length(); 
        int starcnt = 0;
        for(int i = 0; i < lenp; i++)
            if(p[i]=='*') starcnt++;
        if(lens < lenp-starcnt) return false;
        
        vector<bool> match((lens+1)*(lenp+1),false);
        match[0] = true;
        for(int i = 1; i <= lenp; i++){
        	if(p[i-1] == '*') match[i] = true;
        	else break;
        }
        for(int i = 1; i <= lens; i++){
        	for(int j = 1; j <= lenp; j++){
        		if(p[j-1]=='*')
        			match[i*(lenp+1)+j] = match[i*(lenp+1)+j-1] || match[(i-1)*(lenp+1)+j];
        		else
        			match[i*(lenp+1)+j] = (p[j-1]==s[i-1] || p[j-1]=='?') && match[(i-1)*(lenp+1)+j-1];
        	}
        }
        return match[lens*(lenp+1)+lenp];

        // solution above is not that good. Using KMP will have a great improvement.
    }
};