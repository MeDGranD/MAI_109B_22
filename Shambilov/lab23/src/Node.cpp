#include "../include/Node.hpp"

template <typename T>
Node<T>::Node(const T &value): val(value) {}

template <typename T>
T Node<T>::GetVal() const {
    return this->val;
}

template <typename T>
Node<T>* Node<T>::GetLeft() const {
    return this->left;
}

template <typename T>
Node<T>* Node<T>::GetRight() const {
    return this->right;
}

template <typename T>
Node<T>* Node<T>::AddNode(Node* root, const T &value) {
    if (root == nullptr) {
        root = new Node(value);
    }
    else if (value < root->val) {
        root->left = AddNode(root->left, value);
    }
    else if (value > root->val) {
        root->right = AddNode(root->right, value);
    }
    return root;
}

template <typename T>
void Node<T>::TreePrint(Node<T>* root, int64_t depth) const {
    if (root != nullptr) {
        TreePrint(root->right, depth + 1);
        for (int64_t indent = 0 ; indent < depth ; ++indent) {
            std::cout << '\t' ;
        }
        std::cout << root->val << std::endl;
        TreePrint(root->left, depth + 1);
    }
}

template <typename T>
Node<T>* Node<T>::SearchList(Node<T>* deleting_node_right) const {
    if (deleting_node_right->left == nullptr) {
        return deleting_node_right;
    }
    else {
        SearchList(deleting_node_right->left);
    }
}

template <typename T>
void Node<T>::DeleteNode(Node<T>* root, const T &value) {
    if (root == nullptr) return;
    else if (value < root->val) {
        DeleteNode(root->left, value);
    }
    else if (value > root->val) {
        DeleteNode(root->right, value);
    }
    else if (value == root->val) {
        if (root->left == nullptr && root->right == nullptr) {
            root = nullptr;
            delete root;
        }
        else if (root->left != nullptr && root->right != nullptr) {
            Node<T>* temp = SearchList(root->right);
            T temp_val = temp->val;
            DeleteNode(temp, temp->val);
            root->val = temp_val;
        }
        else if (root->left != nullptr && root->right == nullptr) {
            Node<T>* temp = root;
            root = root->left;
            delete temp;
        }
        else if (root->left == nullptr && root->right != nullptr) {
            Node<T>* temp = root;
            root = root->right;
            delete temp;
        }
    }
    else {
        std::cout << "Can`t found this value in the tree" << std::endl;
    }
}

template <typename T>
int64_t Node<T>::FindMaxDepth(Node<T>* root) const {
    if (root == nullptr) {
        return 0;
    }
    int64_t LHeight = FindMaxDepth(root->left);
    int64_t RHeight = FindMaxDepth(root->right);
    return (std::max(LHeight, RHeight) + 1);
}

template <typename T>
int64_t Node<T>::Task(Node<T>* root, int64_t counter) {
    if (root != nullptr) {
        if (root->left && root->right) {
            if (root->val == 2) {
                ++counter;
            }
        }
        else if (root->left && !root->right || !root->left && root->right) {
            if (root->val == 1) {
                ++counter;
            }
        }
        else if (!root->left && !root->right) {
            if (root->val == 0) {
                ++counter;
            }
        }

        Task(root->left, counter);
        Task(root->right, counter);
    }
    return counter;
}

template <typename T>
void Node<T>::DeleteBranch(Node<T>* current_node) {
    if (current_node == nullptr) {
        return;
    }
    DeleteBranch(current_node->left);
    delete current_node;
    DeleteBranch(current_node->right);
}
