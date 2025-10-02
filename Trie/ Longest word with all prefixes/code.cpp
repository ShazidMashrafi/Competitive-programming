#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        int count;
        
        TrieNode() {
            isEnd = false;
            count = 0;
            for (int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                node->children[index] = new TrieNode();
            node = node->children[index];
        }
        node->isEnd = true;
        node->count++;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return node->isEnd;
    }
    
    int countWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index])
                return 0;
            node = node->children[index];
        }
        return node->count;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index])
                return false;
            node = node->children[index];
        }
        return true;
    }

    bool isCompleteString(string word) {
        TrieNode* node = root;
        for(int i = 0; i < word.length(); ++i) {
            int index = word[i] - 'a';
            node = node->children[index];
            
            if(!node || !node->isEnd) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string completeString(vector<string>& strings) {
        
        Trie trie;
        for(auto &s : strings) {
            trie.insert(s);
        }
        
        string longest = "";
        for(auto &s : strings) {
            if(trie.isCompleteString(s)) {
                if(s.length() > longest.length()) {
                    longest = s;
                }
                else if(s.length() == longest.length() && s < longest) {
                    longest = s;
                }
            }
        }

        if(longest == "") longest = "None";
        return longest;
    }
};