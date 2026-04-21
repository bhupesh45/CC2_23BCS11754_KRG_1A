#include <bits/stdc++.h>
using namespace std;

class TrieNode {
  public:
    char ch;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char c) {
        ch = c;
        isTerminal = false;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
  public:
    TrieNode* root = new TrieNode('\0');

    void insertUtil(TrieNode* root, string str) {
        if (str.size() == 0) {
            root->isTerminal = true;
            return;
        }

        int ind = str[0] - 'A';
        TrieNode* child;

        if (root->children[ind] != NULL) {
            child = root->children[ind];
        } else {
            child = new TrieNode(str[0]);
            root->children[ind] = child;
        }

        insertUtil(child, str.substr(1));
    }
    void insert(string str) { insertUtil(root, str); }

    bool searchUtil(TrieNode* root, string str) {
        if (str.size() == 0) {
            return root->isTerminal;
        }

        int ind = str[0] - 'A';
        TrieNode* child;

        if (root->children[ind] != NULL) {
            child = root->children[ind];
        } else {
            return false;
        }

        return searchUtil(child, str.substr(1));
    }

    bool search(string str) { return searchUtil(root, str); }
};

int main() {
    return 0;
}
