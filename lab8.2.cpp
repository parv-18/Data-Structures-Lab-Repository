/*program to implement Tree ADT using a character binary tree using the following operations
1.Insert
2.Preorder
3.Inorder
4.Postorder
5.Search
6.Exit*/

#include <iostream>
using namespace std;

// Structure for a node in the binary tree
struct TreeNode {
    char data;       
    TreeNode* left;  
    TreeNode* right;

    TreeNode(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Class for Binary Tree ADT
class BinaryTree {
private:
    TreeNode* root; 

    TreeNode* insert(TreeNode* node, char value) {
        if (node == nullptr) {
            return new TreeNode(value); 
        }
        if (value < node->data) {
            node->left = insert(node->left, value); 
        } else if (value > node->data) {
            node->right = insert(node->right, value); 
        } else {
            cout << "Error: Duplicate value '" << value << "' not allowed!\n";
        }
        return node;
    }

    // Function for preorder traversal (Root → Left → Right)
    void preorder(TreeNode* node) {
        if (node) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    //Function for inorder traversal (Left → Root → Right)
    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Function for postorder traversal (Left → Right → Root)
    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
    
    // Function to search for a character in BST
    bool search(TreeNode* node, char key) {
        if (node == nullptr) return false; 
        if (node->data == key) return true; 
        if (key < node->data) return search(node->left, key); 
        return search(node->right, key); 
    }

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a node into BST
    void insert(char value) {
        root = insert(root, value);
    }

    // Function to perform preorder traversal
    void preorder() {
        if (!root) {
            cout << "Tree is empty!\n";
            return;
        }
        cout << "Preorder Traversal: ";
        preorder(root);
        cout << endl;
    }

    // Function to perform inorder traversal
    void inorder() {
        if (!root) {
            cout << "Tree is empty!\n";
            return;
        }
        cout << "Inorder Traversal: ";
        inorder(root);
        cout << endl;
    }

    // Function to perform postorder traversal
    void postorder() {
        if (!root) {
            cout << "Tree is empty!\n";
            return;
        }
        cout << "Postorder Traversal: ";
        postorder(root);
        cout << endl;
    }

    // Function to search for a character in the tree
    void search(char key) {
        if (search(root, key)) {
            cout << "Character '" << key << "' is present in the tree.\n";
        } else {
            cout << "Character '" << key << "' is NOT found in the tree.\n";
        }
    }
};

int main() {
    BinaryTree tree;
    int choice;
    char value;

    do {
        cout << "\nBinary Tree Operations:";
        cout << "\n1. Insert";
        cout << "\n2. Preorder Traversal";
        cout << "\n3. Inorder Traversal";
        cout << "\n4. Postorder Traversal";
        cout << "\n5. Search";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                tree.preorder();
                break;
            case 3:
                tree.inorder();
                break;
            case 4:
                tree.postorder();
                break;
            case 5:
                cout << "Enter character to search: ";
                cin >> value;
                tree.search(value);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
