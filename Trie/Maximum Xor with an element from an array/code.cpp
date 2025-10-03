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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int> >& queries) {
        int n = nums.size();
        int q = queries.size();
        sort(nums.begin(), nums.end());
        vector<pair<pair<int,int>, int>> query;
        for(int i = 0; i < q; ++i) {
            query.push_back({{queries[i][1], queries[i][0]}, i});
        }
        sort(query.begin(), query.end());
        vector<int>ans(q, 0);

        Trie trie;
        int idx = 0;
        for(int i = 0; i < q; ++i) {
            int ai = query[i].first.first;
            int xi = query[i].first.second;
            int pos = query[i].second;

            while(idx < n && nums[idx] <= ai) {
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx == 0)    ans[pos] = -1;
            else ans[pos] = trie.getMaxXOR(xi);
        }
        return ans;
    }
};