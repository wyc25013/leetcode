#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
       	vector<int> a((s.length()+1)*t.length()+t.length(),-1);
    	return helper(s,0,t,0,a);

        /* or it could be neater
        /* dp[i][j] ==> matches between s[0..i] and t[0..j]
        /* dp[i+1][j+1] = s[i+1]==t[j+1] ? dp[i][j] : 0 + dp[i][j+1]
        /* ==> reduce to 
        /* dp[j+1] += s[i+1]==t[j+1] ? dp[j] : 0;

        int sl = s.length(), tl = t.length();
        vector<int> dp(tl+1,0); dp[0]=1;
        for(int i=0;i<sl;i++){
            int jj = tl-1 < i ? tl-1 : i; 
            for(int j=jj; j >= 0 ;j--){
                if (s[i]==t[j])
                    dp[j+1]+=dp[j];
            }
        }
        return dp[tl];
        
        */    
    }

    int helper(string s, int ps, string t, int pt, vector<int>& a){
    	int ret = 0;
    	if(pt==t.length()) return 1;
    	if(s.length()-ps < t.length()-pt) return 0;
    	int pos = ps-1;
    	do{
	    	pos = s.find(t.substr(pt,1),pos+1);
	    	if(pos==string::npos) break;
	    	if(a[(pos+1)*t.length()+pt+1] != -1)
	    		ret += a[(pos+1)*t.length()+pt+1];
	    	else{
	    		int lo = helper(s,pos+1,t,pt+1,a);
	    		ret += lo;
	    		a[(pos+1)*t.length()+pt+1] = lo;
	    	}
    	}while(pos != s.length()-1);
    	return ret;	 
    }
};

int main(){
	Solution soln;
	cout<<soln.numDistinct("abababababababababababababababababababababababababab","abbbbb")<<endl;
}