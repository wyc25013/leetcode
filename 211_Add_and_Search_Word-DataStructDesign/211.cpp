#include <iostream>
using namespace std;

class TrieNode {
public:
    bool ifleaf;
    TrieNode* arr[26];
    // Initialize your data structure here.
    TrieNode() {
        ifleaf = false;
        for(int i = 0; i < 26; i++)
            arr[i] = NULL;      
    }
};

class WordDictionary {
public:
	WordDictionary(){
		root = new TrieNode();
	}
    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.length();
        if(!len) return;
        TrieNode* cur = root;
        for(int i = 0; i < len; i++){
        	if(!cur->arr[word[i]-97]){
        		TrieNode* newnode = new TrieNode();
				cur->arr[word[i]-97] = newnode;
        	}
        	cur = cur->arr[word[i]-97];
        }
        cur->ifleaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        int len = word.length();
        if(!len) return true;
        return helper(word,root,0);
    }

    bool helper(string word, TrieNode* start,int pos){
    	int len = word.length();
        TrieNode* cur = start;
        for(int i = pos; i < len; i++){
        	if(word[i] == '.'){
        		for(int j = 0; j < 26; j++){
        			if(cur->arr[j]){
        				if(helper(word,cur->arr[j],i+1))
        					return true;
        			}
        		}
        		return false;
        	}else{
        		if(!cur->arr[word[i]-97]){
        			return false;	
        		} else
        			cur = cur->arr[word[i]-97];
        	}
        }
        return cur->ifleaf;
    }
private:
    TrieNode* root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");