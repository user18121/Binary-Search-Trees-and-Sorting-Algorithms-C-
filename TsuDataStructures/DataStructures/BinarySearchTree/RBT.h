#pragma once
#include <iostream>



using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;
    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
    Node* root;

    void rotateLeft(Node*& root, Node*& pt);

    void rotateRight(Node*& root, Node*& pt);

    void fixViolation(Node*& root, Node*& pt);

    void inorderHelper(Node* root) {
        if (root == nullptr)
            return;
        inorderHelper(root->left);
        cout << root->data << " ";
        inorderHelper(root->right);
    }

    void printTreeHelper(Node* node, ostream& out, int level) const;

public:
    RedBlackTree() : root(nullptr) {}

    inline void easyAdd();

    friend ostream&operator<<(ostream& out, const RedBlackTree& tree) {
        tree.printTreeHelper(tree.root,out,0);
        return out;
    }
    void insert(const int& data) {
        Node* pt = new Node(data);
        root = BSTInsert(root, pt);
        fixViolation(root, pt);
    }

    Node* BSTInsert(Node* root, Node* pt) {
        if (root == nullptr)
            return pt;
        if (pt->data < root->data) {
            root->left = BSTInsert(root->left, pt);
            root->left->parent = root;
        } else if (pt->data > root->data) {
            root->right = BSTInsert(root->right, pt);
            root->right->parent = root;
        }
        return root;
    }



    void inorder() {
        inorderHelper(root);
    }

};

inline void RedBlackTree::printTreeHelper(Node* node, ostream& out, int level) const {
    if (node == nullptr) return;


    if (node->right) {
        printTreeHelper(node->right, out, level + 1);
    }


    if (level > 0) {
        out << string(level * 4, ' ');
    }
    out << node->data << endl;


    if (node->left) {
        printTreeHelper(node->left, out, level + 1);
    }
}

void RedBlackTree::rotateLeft(Node*& root, Node*& pt) {
    Node* pt_right = pt->right;
    pt->right = pt_right->left;
    if (pt->right != nullptr)
        pt->right->parent = pt;
    pt_right->parent = pt->parent;
    if (pt->parent == nullptr)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;
    pt_right->left = pt;
    pt->parent = pt_right;
}
void RedBlackTree::rotateRight(Node*& root, Node*& pt) {
    Node* pt_left = pt->left;
    pt->left = pt_left->right;
    if (pt->left != nullptr)
        pt->left->parent = pt;
    pt_left->parent = pt->parent;
    if (pt->parent == nullptr)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;
    pt_left->right = pt;
    pt->parent = pt_left;
}
void RedBlackTree::fixViolation(Node*& root, Node*& pt) {
    Node* parent_pt = nullptr;
    Node* grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            Node* uncle_pt = grand_parent_pt->right;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else {
            Node* uncle_pt = grand_parent_pt->left;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}

inline void RedBlackTree::easyAdd(){
    insert(30);
    insert(20);
    insert(40);
    insert(10);
    insert(25);
    insert(35);
    insert(50);
}
