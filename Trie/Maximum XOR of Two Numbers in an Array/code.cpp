#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
    struct TrieNode {
        TrieNode* children[2];
        
        TrieNode() {
            for (int i = 0; i < 2; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(int num) {
        TrieNode* node = root;
        for(int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if(!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int getMaxXOR(int num) {
        TrieNode* node = root;
        int mx = 0;
        for(int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int op = 1 - bit;
            if(node->children[op]) {
                mx |= (1 << i);
                node = node->children[op];
            } else {
                node = node->children[bit];
            }
        }
        return mx;
    }
};

class Solution {
public:
    Trie trie;
    int ans = 0;
    int findMaximumXOR(vector<int>& nums) {
        for(int num : nums) {
            trie.insert(num);
        }
        for(int num : nums) {
            ans = max(ans, trie.getMaxXOR(num));
        }

        return ans;
    }
};