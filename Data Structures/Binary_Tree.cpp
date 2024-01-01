#include <iostream>
#include <queue>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        deleteTree(root);
    }

    int getHeight() {
        return height(root);
    }

    int getSize() {
        return size(root);
    }

    int getLevel(int value) {
        return level(root, value, 1);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void remove(int value) {
        root = removeNode(root, value);
    }   

    bool search(int value) {
        return searchNode(root, value);
    }

    void breadthFirstTraversal() {
        if (root == nullptr) return;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            std::cout << current->data << " ";

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);

            q.pop();
        }
    }

    void preOrderTraversal() {
        preOrder(root);
    }

    void inOrderTraversal() {
        inOrder(root);
    }

    void postOrderTraversal() {
        postOrder(root);
    }

private:
    int height(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

    int size(TreeNode* node) {
        if (node == nullptr) return 0;
        return 1 + size(node->left) + size(node->right);
    }

    int level(TreeNode* node, int value, int currentLevel) {
        if (node == nullptr) return 0;

        if (node->data == value) return currentLevel;

        int downLevel = level(node->left, value, currentLevel + 1);
        if (downLevel != 0) return downLevel;

        downLevel = level(node->right, value, currentLevel + 1);
        return downLevel;
    }

    TreeNode* insertNode(TreeNode* node, int value) {
        if (node == nullptr) return new TreeNode(value);

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    TreeNode* removeNode(TreeNode* node, int value) {
        if (node == nullptr) return nullptr;

        if (value < node->data) {
            node->left = removeNode(node->left, value);
        } else if (value > node->data) {
            node->right = removeNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }

        return node;
    }

    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    bool searchNode(TreeNode* node, int value) {
        if (node == nullptr) return false;

        if (value == node->data) return true;
        if (value < node->data) return searchNode(node->left, value);
        return searchNode(node->right, value);
    }

    void deleteTree(TreeNode* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    void preOrder(TreeNode* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(TreeNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void postOrder(TreeNode* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->data << " ";
        }
    }
};

int main() {
    // Example usage
    BinaryTree myTree;
    myTree.insert(50);
    myTree.insert(30);
    myTree.insert(20);
    myTree.insert(40);
    myTree.insert(70);
    myTree.insert(60);
    myTree.insert(80);

    std::cout << "Height of the tree: " << myTree.getHeight() << std::endl;
    std::cout << "Size of the tree: " << myTree.getSize() << std::endl;

    std::cout << "Breadth-First Traversal: ";
    myTree.breadthFirstTraversal();
    std::cout << std::endl;

    std::cout << "PreOrder Traversal: ";
    myTree.preOrderTraversal();
    std::cout << std::endl;

    std::cout << "InOrder Traversal: ";
    myTree.inOrderTraversal();
    std::cout << std::endl;

    std::cout << "PostOrder Traversal: ";
    myTree.postOrderTraversal();
    std::cout << std::endl;

    return 0;
}
