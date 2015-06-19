#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
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
    
    int romanToInt(string s) {
        /*
        map<char,int> m;
        m.insert(pair<char,int>('I',1));
        m.insert(pair<char,int>('V',5));
        m.insert(pair<char,int>('X',10));
        m.insert(pair<char,int>('L',50));
        m.insert(pair<char,int>('C',100));
        m.insert(pair<char,int>('D',500));
        m.insert(pair<char,int>('M',1000));
        */
        
        
    	int result = 0;
    	int len = s.length();
        if(!len)
        	return 0;
        else{
            for (int i = 0; i < len; i++){
        	    if(AtoI(s[i+1]) > AtoI(s[i]))
        		    result-= AtoI(s[i]);
        	    else
        		    result+= AtoI(s[i]);
            }
        }
        return result;
    }
};

int main(){
	Solution soln;
	cout << soln.romanToInt("MCMLIV") << endl;
	return 0;
}