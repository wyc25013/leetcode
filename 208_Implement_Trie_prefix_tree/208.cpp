#include <iostream>
#include <vector>
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

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
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

    // Returns if the word is in the trie.
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

    // Returns if there is any word in the trie
    // that starts with the given prefix.
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

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");