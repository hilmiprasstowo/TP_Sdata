#include <iostream>
using namespace std;

struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(char value) {
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, char value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void preorderTraversal(TreeNode* node) {
    if (node) {
        cout << node->value << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

void inorderTraversal(TreeNode* node) {
    if (node) {
        inorderTraversal(node->left);
        cout << node->value << " ";
        inorderTraversal(node->right);
    }
}

void postorderTraversal(TreeNode* node) {
    if (node) {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->value << " ";
    }
}

void printTree(TreeNode* node, int space = 0, int level_gap = 5) {
    if (node == NULL)
        return;

    space += level_gap;

    printTree(node->right, space);

    cout << endl;
    for (int i = level_gap; i < space; i++)
        cout << " ";
    cout << node->value << endl;

    printTree(node->left, space);
}

int main() {
    TreeNode* root = NULL;
    char value;

    for (int i = 0; i < 7; ++i) {
        cout << "Masukkan nilai " << i + 1 << ": ";
        cin >> value;
        root = insertNode(root, value);
    }

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;

    cout << "\nVisualisasi Binary Tree:" << endl;
    printTree(root);

    return 0;
}
