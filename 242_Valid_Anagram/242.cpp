class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> ret(26,0);
        for(int i = 0; i < s.length(); i++){
            ret[s[i]-'a']++;
            ret[t[i]-'a']--;
        }
        for(int i = 0; i < 26; i++){
            if(ret[i] != 0)
                return false;
        }
        return true;
        /*
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
        */
    }
};