#pragma once
#include <iostream>
#include <queue>



template<typename T>
class BST
{
private:
    struct Node
    {
        T value;
        Node *left{};
        Node *right{};
    };

public:
    BST() = default;
    BST(const BST &other);
    BST &operator=(const BST &other);
    ~BST();

    void insert(const T &value);
    bool search(const T &value) const;
    void erase(const T &value);
    bool empty() const { return !root_; }

    void easyAdd();

    void inorder(std::ostream &out = std::cout) const;
    void preorder(std::ostream &out = std::cout) const;
    void postorder(std::ostream &out = std::cout) const;

    friend std::ostream& operator<<(std::ostream& out, const BST<T>& tree) {
        tree.printTreeHelper(tree.root_, out, 0);
        return out;
    }

private:
    void inorder(Node *root, std::ostream &out) const;
    void preorder(Node *root, std::ostream &out) const;
    void postorder(Node *root, std::ostream &out) const;

private:
    Node *root_{};

    void printTreeHelper(Node *node, std::ostream &out, int space) const;
};

template<typename T>
BST<T>::BST(const BST &other)
{
    if (other.empty())
        return;

    root_ = new Node{other.root_->value};

    std::queue<Node *> q;
    std::queue<Node *> other_q;

    q.push(root_);
    other_q.push(other.root_);

    while (!q.empty()) {
        auto *node = q.front();
        auto *other_node = other_q.front();

        q.pop();
        other_q.pop();

        if (other_node->left) {
            auto *new_node = new Node{other_node->left->value};
            node->left = new_node;
            q.push(new_node);
            other_q.push(other_node->left);
        }

        if (other_node->right) {
            auto *new_node = new Node{other_node->right->value};
            node->right = new_node;
            q.push(new_node);
            other_q.push(other_node->right);
        }
    }
}

template<typename T>
BST<T> &BST<T>::operator=(const BST &other)
{
    if (this != &other) {
        this->~BST();
        new (this) BST(other);
    }
    return *this;
}

template<typename T>
BST<T>::~BST()
{
    if (empty())
        return;

    std::queue<Node *> q;
    q.push(root_);

    while (!q.empty()) {
        auto *node = q.front();
        q.pop();

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);

        delete node;
    }
}

template<typename T>
void BST<T>::insert(const T &value)
{
    Node *parent = nullptr;
    Node *walker = root_;

    while (walker) {
        if (value < walker->value) {
            parent = walker;
            walker = walker->left;
        } else if (walker->value < value) {
            parent = walker;
            walker = walker->right;
        } else {
            return;
        }
    }

    auto *new_node = new Node{value};

    if (!parent)
        root_ = new_node;
    else if (value < parent->value)
        parent->left = new_node;
    else
        parent->right = new_node;
}

template<typename T>
bool BST<T>::search(const T &value) const
{
    auto *walker = root_;

    while (walker) {
        if (value < walker->value) {
            walker = walker->left;
        } else if (walker->value < value) {
            walker = walker->right;
        } else {
            return true;
        }
    }
    return false;
}

template<typename T>
void BST<T>::erase(const T &value)
{
    Node *parent = nullptr;
    Node *walker = root_;

    while (walker) {
        if (value < walker->value) {
            parent = walker;
            walker = walker->left;
        } else if (walker->value < value) {
            parent = walker;
            walker = walker->right;
        } else {
            break;
        }
    }

    if (!walker)
        return;

    if (walker->left && walker->right) {
        Node *succ_parent = walker;
        Node *succ = walker->right;

        while (succ->left) {
            succ_parent = succ;
            succ = succ->left;
        }

        walker->value = succ->value;
        parent = succ_parent;
        walker = succ;
    }

    Node *child = walker->left ? walker->left : walker->right;

    if (!parent)
        root_ = child;
    else if (walker == parent->left)
        parent->left = child;
    else
        parent->right = child;

    delete walker;
}

template<typename T>
void BST<T>::inorder(std::ostream &out) const
{
    inorder(root_, out);
}

template<typename T>
void BST<T>::preorder(std::ostream &out) const
{
    preorder(root_, out);
}

template<typename T>
void BST<T>::postorder(std::ostream &out) const
{
    postorder(root_, out);
}

template<typename T>
void BST<T>::inorder(Node *root, std::ostream &out) const
{
    if (root) {
        inorder(root->left, out);
        out << root->value << " ";
        inorder(root->right, out);
    }
}

template<typename T>
void BST<T>::preorder(Node *root, std::ostream &out) const
{
    if (root) {
        out << root->value << " ";
        preorder(root->left, out);
        preorder(root->right, out);
    }
}

template<typename T>
void BST<T>::postorder(Node *root, std::ostream &out) const
{
    if (root) {
        postorder(root->left, out);
        postorder(root->right, out);
        out << root->value << " ";
    }
}

template<class T>
void BST<T>::printTreeHelper(Node* node, std::ostream& out, int space) const
{
    if (node == nullptr) return;


    space += 4;


    if (node->right) {
        printTreeHelper(node->right, out, space);
    }


    out << std::endl;
    for (int i =4; i < space; i++) {
        out << " ";
    }
    out << node->value << std::endl;


    if (node->left) {
        printTreeHelper(node->left, out, space);
    }
}
template<class T>
void BST<T>::easyAdd() {
    insert(30);
    insert(20);
    insert(40);
    insert(10);
    insert(25);
    insert(35);
    insert(50);
}
