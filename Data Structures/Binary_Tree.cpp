#include <iostream>
#include <queue>

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

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

    int getLevel(T value) {
        return level(root, value, 1);
    }

    void insert(T value) {
        root = insertNode(root, value);
    }

    void remove(T value) {
        root = removeNode(root, value);
    }   

    bool search(T value) {
        return searchNode(root, value);
    }

    void breadthFirstTraversal() {
        if (root == nullptr) return;

        std::queue<TreeNode<T>*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode<T>* current = q.front();
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
    int height(TreeNode<T>* node) {
        if (node == nullptr) return 0;
        return 1 + std::max(height(node->left), height(node->right));
    }

    int size(TreeNode<T>* node) {
        if (node == nullptr) return 0;
        return 1 + size(node->left) + size(node->right);
    }

    int level(TreeNode<T>* node, T value, int currentLevel) {
        if (node == nullptr) return 0;

        if (node->data == value) return currentLevel;

        int downLevel = level(node->left, value, currentLevel + 1);
        if (downLevel != 0) return downLevel;

        downLevel = level(node->right, value, currentLevel + 1);
        return downLevel;
    }

    TreeNode<T>* insertNode(TreeNode<T>* node, T value) {
        if (node == nullptr) return new TreeNode<T>(value);

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else if (value > node->data) {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    TreeNode<T>* removeNode(TreeNode<T>* node, T value) {
        if (node == nullptr) return nullptr;

        if (value < node->data) {
            node->left = removeNode(node->left, value);
        } else if (value > node->data) {
            node->right = removeNode(node->right, value);
        } else {
            if (node->left == nullptr) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode<T>* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }

        return node;
    }

    TreeNode<T>* findMin(TreeNode<T>* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    bool searchNode(TreeNode<T>* node, T value) {
        if (node == nullptr) return false;

        if (value == node->data) return true;
        if (value < node->data) return searchNode(node->left, value);
        return searchNode(node->right, value);
    }

    void deleteTree(TreeNode<T>* node) {
        if (node != nullptr) {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    void preOrder(TreeNode<T>* node) {
        if (node != nullptr) {
            std::cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(TreeNode<T>* node) {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void postOrder(TreeNode<T>* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            std::cout << node->data << " ";
        }
    }
};

int main() {
    // Example usage
    BinaryTree<int> myTree;
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
