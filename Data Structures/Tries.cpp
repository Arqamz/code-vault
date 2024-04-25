#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;

    TrieNode() : endOfWord(false) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.count(c) == 0) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.count(c) == 0) {
                return false;
            }
            current = current->children[c];
        }
        return current->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* current = root;
        for (char c : prefix) {
            if (current->children.count(c) == 0) {
                return false;
            }
            current = current->children[c];
        }
        return true;
    }

    void printAllWords(TrieNode* node, string word = "") {
        if (node->endOfWord) {
            cout << word << endl;
        }
        for (auto it : node->children) {
            printAllWords(it.second, word + it.first);
        }
    }

    void printAllWords() {
        printAllWords(root);
    }
};

int main() {
    Trie trie;
    trie.insert("hello");
    cout << trie.search("hello") << endl;  // prints: 1
    cout << trie.search("hell") << endl;   // prints: 0
    cout << trie.startsWith("hell") << endl; // prints: 1
    trie.printAllWords();
    return 0;
}