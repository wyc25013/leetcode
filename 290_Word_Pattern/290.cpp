class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> cs;
        unordered_map<string, char> sc;
        for(int i = 0; i < pattern.length(); ++i){
            if(str.empty()) return false;
            string tmp = str.substr(0, str.find(" "));
            if(cs.find(pattern[i]) == cs.end() && sc.find(tmp) == sc.end()){
                cs[pattern[i]] = tmp;
                sc[tmp] = pattern[i];
            }else{
                if(cs[pattern[i]] != tmp) return false;
                if(sc[tmp] != pattern[i]) return false;
            }
            if(str.find(" ") != string::npos)
                str = str.substr(str.find(" ")+1);
            else
                str = "";
        }
        return str.empty();
    }
};