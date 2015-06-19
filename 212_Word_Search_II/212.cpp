class TrieNode {
public:
    bool ifleaf;
    TrieNode* arr[26];
    TrieNode() {
        ifleaf = false;
        for(int i = 0; i < 26; i++)
            arr[i] = NULL;      
    }
};
class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        int len = s.length();
        TrieNode* cur = root;
        for(int i = 0; i < len; i++){
            if(!cur->arr[s[i]-97]){
                TrieNode* newnode = new TrieNode();
                cur->arr[s[i]-97] = newnode;  
            }  
            cur = cur->arr[s[i]-97];
        }
        cur->ifleaf = true;
    }
    bool search(string key) {
        int len = key.length();
        TrieNode* cur = root;
        for(int i = 0; i < len-1; i++){
            if(cur->arr[key[i]-97] == NULL)
                return false;
            else
                cur = cur->arr[key[i]-97];
        }
        if(cur->arr[key[len-1]-97] == NULL)
            return false;
        else{
            if(cur->arr[key[len-1]-97]->ifleaf != true)
                return false;
            else
                return true;
        }
    }
    bool startsWith(string prefix) {
        int len = prefix.length();
        TrieNode* cur = root;
        for(int i = 0; i < len-1; i++){
            if(cur->arr[prefix[i]-97] == NULL)
                return false;
            else
                cur = cur->arr[prefix[i]-97];
        }
        if(cur->arr[prefix[len-1]-97] == NULL)
            return false;
        else
            return true;
    }
private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& word) {
		int row = board.size();
		int col = board[0].size();
		vector<vector<bool> > map(row,vector<bool>(col,false));
	
		Trie tr; int longest = 0; int ws = word.size();
		for(int i = 0; i < ws; i++){
			tr.insert(word[i]);
			if(word[i].length() > longest)
				longest = word[i].length();
		}

		vector<string> ret;
		
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				string s(1,board[i][j]);
				if(tr.search(s))
					ret.push_back(s);
				if(tr.startsWith(s)){
					map[i][j] = true;
					helper(s,longest,ws,tr,ret,board,map,i,j);
					map[i][j] = false;
				}
				if(ret.size()==ws) return ret;
			}
		}
		return ret;
	}
	void helper(string& s,int longest,int ws,Trie& tr,vector<string>& ret, 
				vector<vector<char> >& board,vector<vector<bool> >& map,int i, int j)
	{
		if(s.length() > longest) return;
		else {
			if(tr.search(s)){
				bool ifs = true;
				for(int k = 0; k < ret.size();k++)
					if(ret[k]==s) 
						ifs = false;
				if(ifs) ret.push_back(s);
			}
			if(ret.size()==ws) return;

			int row = board.size();
			int col = board[0].size();
			if(i < row-1 && map[i+1][j] == false){
				s.push_back(board[i+1][j]);
				if(tr.startsWith(s)){
					map[i+1][j] = true;
					helper(s,longest,ws,tr,ret,board,map,i+1,j);
					map[i+1][j] = false;
				}
				s.pop_back();
			}
			if(i > 0 && map[i-1][j] == false){
				s.push_back(board[i-1][j]);
				if(tr.startsWith(s)){
					map[i-1][j] = true;
					helper(s,longest,ws,tr,ret,board,map,i-1,j);
					map[i-1][j] = false;
				}
				s.pop_back();
			}
			if(j < col-1 && map[i][j+1] == false){
				s.push_back(board[i][j+1]);
				if(tr.startsWith(s)){
					map[i][j+1] = true;
					helper(s,longest,ws,tr,ret,board,map,i,j+1);
					map[i][j+1] = false;
				}
				s.pop_back();
			}
			if(j > 0 && map[i][j-1] == false){
				s.push_back(board[i][j-1]);
				if(tr.startsWith(s)){
					map[i][j-1] = true;
					helper(s,longest,ws,tr,ret,board,map,i,j-1);
					map[i][j-1] = false;
				}
				s.pop_back();
			}
		}
	}
};