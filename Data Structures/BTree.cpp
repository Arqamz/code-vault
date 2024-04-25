#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class BTreeNode {
public:
    BTreeNode(bool isLeaf = false) : isLeaf(isLeaf) {}

    void insertNonFull(T k) {
        int i = keys.size() - 1;
        if (isLeaf) {
            keys.push_back(k);
            sort(keys.begin(), keys.end());
        } else {
            while (i >= 0 && keys[i] > k)
                i--;
            if (child_ptr[i+1]->keys.size() == (2 * ORDER - 1)) {
                splitChild(i+1, child_ptr[i+1]);
                if (keys[i+1] < k)
                    i++;
            }
            child_ptr[i+1]->insertNonFull(k);
        }
    }

    void splitChild(int i, BTreeNode* node) {
        BTreeNode* newNode = new BTreeNode(node->isLeaf);

        for (int j = 0; j < ORDER - 1; j++)
            newNode->keys.push_back(node->keys[j + ORDER]);

        if (!node->isLeaf) {
            for (int j = 0; j < ORDER; j++)
                newNode->child_ptr.push_back(node->child_ptr[j + ORDER]);
        }

        node->keys.resize(ORDER - 1);

        child_ptr.insert(child_ptr.begin() + i + 1, newNode);

        keys.insert(keys.begin() + i, node->keys[ORDER - 1]);
    }

    BTreeNode* searchKey(T k) {
        int i = 0;
        while (i < keys.size() && k > keys[i])
            i++;
        if (i < keys.size() && keys[i] == k)
            return this;
        if (isLeaf)
            return nullptr;
        return child_ptr[i]->searchKey(k);
    }

    bool isLeaf;
    vector<T> keys;
    vector<BTreeNode*> child_ptr;

    static const int ORDER = 3;
};

template <typename T>
class BTree {
public:
    BTree() : root(new BTreeNode<T>(true)) {}

    BTreeNode<T>* searchKey(T k) {
        return (root == nullptr)? nullptr : root->searchKey(k);
    }

    void insertKey(T k) {
        if (root->keys.size() == (2 * BTreeNode<T>::ORDER - 1)) {
            BTreeNode<T>* newNode = new BTreeNode<T>();
            newNode->child_ptr.push_back(root);
            newNode->splitChild(0, root);
            int i = 0;
            if (newNode->keys[0] < k)
                i++;
            newNode->child_ptr[i]->insertNonFull(k);
            root = newNode;
        } else
            root->insertNonFull(k);
    }

private:
    BTreeNode<T>* root;
};

int main() {
    BTree<int> bTree;

    // Inserting keys
    bTree.insertKey(10);
    bTree.insertKey(20);
    bTree.insertKey(5);
    bTree.insertKey(6);
    bTree.insertKey(12);

    // Searching keys
    if (bTree.searchKey(10) != nullptr) {
        cout << "Key 10 found\n";
    } else {
        cout << "Key 10 not found\n";
    }

    if (bTree.searchKey(15) != nullptr) {
        cout << "Key 15 found\n";
    } else {
        cout << "Key 15 not found\n";
    }

    return 0;
}
