#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T &value): data(value) {}

template<typename T>
T Node<T>::get_data() const {
    return this->data;
}
template<typename T>
Node<T> *Node<T>::get_left() const {
    return this->left;
}
template<typename T>
Node<T> *Node<T>::get_right() const {
    return this->right;
}

template<typename T>
void Node<T>::count_nodes(Node *node, int64_t *counter) const {
    if (node == nullptr) {
        return;
    }
    ++(*counter);
    count_nodes(node->left, counter);
    count_nodes(node->right, counter);
}

template<typename T>
void Node<T>::print_nodes(std::ostream &out, Node<T> *node, int64_t height) const {
    if (node != nullptr) {
        print_nodes(out, node->right, height + 1);
        for (int64_t i = 0; i < height; ++i) {
            out << '\t';
        }
        out << node->data << '\n';
        print_nodes(out, node->left, height + 1);
    }
}

template<typename T>
void Node<T>::print_nodes(Node<T> *node, int64_t height) const {
    if (node != nullptr) {
        print_nodes(node->right, height + 1);
        for (int64_t i = 0; i < height; ++i) {
            std::cout << '\t';
        }
        std::cout << node->data << '\n';
        print_nodes(node->left, height + 1);
    }
}

template<typename T>
void Node<T>::add_leaf(Node *current_node, const T &value) {
    while (true) {
        if (value < current_node->data) {
            if (current_node->left == nullptr) {
                current_node->left = new Node(value);
                break;
            } else {
                current_node = current_node->left;
            }
        } else if (value > current_node->data) {
            if (current_node->right == nullptr) {
                current_node->right = new Node(value);
                break;
            } else {
                current_node = current_node->right;
            }
        } else {
            std::cout << "Existing node with same value found. Please use another value." << std::endl;
            break;
        }
    }
}

template<typename T>
Node<T> *Node<T>::min_value_node(Node<T>* const node) const {
    Node<T> *current = node;
    // Go down to search for leftmost leaf
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

template<typename T>
void Node<T>::bypass(Node<T> *node) const {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << std::endl;
    bypass(node->left);
    bypass(node->right);
}

template<typename T>
Node<T> *Node<T>::delete_node(Node<T> *current_node, const T &value) {
    if (current_node == nullptr)
        return current_node;

    // If the value is smaller than the current_node's
    // value, then it is in left subtree
    if (value < current_node->data)
        current_node->left = delete_node(current_node->left, value);

    // If the value is greater than the current_node's
    // value, then it is in right subtree
    else if (value > current_node->data)
        current_node->right = delete_node(current_node->right, value);

    // If value is same as current_node's value, then this node should be deleted
    else {
        // Node has no child
        if (current_node->left == nullptr and current_node->right == nullptr) {
            delete current_node;
            return nullptr;
        }
        // Node with only one child or no child
        else if (current_node->left == nullptr) {
            Node<T> *temp = current_node->right;
            delete current_node;
            return temp;
        } else if (current_node->right == nullptr) {
            Node<T> *temp = current_node->left;
            delete current_node;
            return temp;
        }

        // If node has two children, then get the smallest node in the right subtree
        Node<T> *temp = min_value_node(current_node->right);
        // Copy it's content to this node
        current_node->data = temp->data;
        // Delete the temp node
        current_node->right = delete_node(current_node->right, temp->data);
    }
    return current_node;
}

template<typename T>
void Node<T>::delete_branch(Node<T> *current_node) {
    if (current_node == nullptr)
        return;
    delete_branch(current_node->left);
    delete_branch(current_node->right);
    delete current_node;
}