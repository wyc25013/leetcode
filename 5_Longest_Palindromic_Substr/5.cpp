#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
  		int len = s.size();
  		if(len == 1)
  		    return s;
  		int longest = 0;
  		int hind;
  		
  		int *mx = new int[len*len];
        for(int i = 0;i < len;i++){
            for(int j = i;j<len;j++){
                if(i!=j)            
                    mx[i*len+j] = 0;
                else
                    mx[i*len+j] = 1;
            }
        }
        
  		for (int i = 1; i < len; i++) {
  			for(int j = 0; j+i < len; j++){
  				if(s[j] == s[j+i]){
  					if(i==1||(j+1<=j+i-1 && mx[(j+1)*len+j+i-1]==1)){
  						mx[j*len+j+i] = 1;
  						if(longest < i+1){
  							longest = i+1;
  							hind = j;
  						}
  					}
  				}

  			}
  		}      
        delete[] mx;
  		return s.substr(hind,longest);
    }
};

int main(){
	Solution soln;
	cout << soln.longestPalindrome("abbbbfabbfbbbfabbbbfabbba") <<endl;
	return 0;
}