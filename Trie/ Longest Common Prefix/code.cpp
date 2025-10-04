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
            if (!node->children[index]){
                node->children[index] = new TrieNode();
                node->count++;
            }
            node = node->children[index];
        }
        node->isEnd = true;
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

    void getLCP(string str, string &ans) {
        TrieNode* node = root;
        
        for (char ch : str) {
            if (node->count != 1 || node->isEnd)    return;   
            ans.push_back(ch);
            int index = ch - 'a';
            node = node->children[index];
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    if (n == 0) return "";
    
    Trie trie;
    for(int i = 0; i < n; ++i) {
        trie.insert(arr[i]);
    }
    
    string ans = "";
    trie.getLCP(arr[0], ans);
    
    return ans;
}