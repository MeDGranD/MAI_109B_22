#include "../include/Node.hpp"


template<typename T>
T Node<T>::get_data() const
{
    return this->data;
}
template<typename T>
Node<T> *Node<T>::get_left() const
{
    return this->left;
}
template<typename T>
Node<T> *Node<T>::get_right() const
{
    return this->right;
}
template<typename T>
Node<T>::Node(const T &new_data)
{
    this->data = new_data;
}
template<typename T>
void Node<T>::bypass(const Node<T> *node) const
{
    if (node == nullptr) {
        return;
    }
    Node<T>::bypass(node->left);
    std::cout << node->data << ' ';
    Node<T>::bypass(node->right);
}
template<typename T>
int64_t Node<T>::b_tree_bypass(const Node<T> *node) const
{
    if (node == nullptr) {
        return 2;
    }
    int64_t first_node = Node<T>::b_tree_bypass(node->left);
    int64_t second_node = Node<T>::b_tree_bypass(node->right);
    return (first_node == second_node) && (first_node + second_node != 0);
}
template<typename T>
void Node<T>::print_nodes(Node<T> *node, int64_t height) const
{
    if (!(node == nullptr)) {
        print_nodes(node->right, height + 1);
        for (int64_t i = 0; i < height; ++i) {
            std::cout << '\t';
        }
        std::cout << node->data << '\n';
        print_nodes(node->left, height + 1);
    }
}
template<typename T>
void Node<T>::print_nodes(Node<T> *node, int64_t height, std::ostream &out) const
{
    if (!(node == nullptr)) {
        print_nodes(node->right, height + 1);
        for (int64_t i = 0; i < height; ++i) {
            out << '\t';
        }
        out << node->data << '\n';
        print_nodes(node->left, height + 1);
    }
}
template<typename T>
Node<T> *Node<T>::add_leaf(const T &insert_data, Node<T> *cur_node)
{
    if (cur_node == nullptr) {
        cur_node = new Node(insert_data);
    }
    else if (insert_data < cur_node->data) {

        cur_node->left = add_leaf(insert_data, cur_node->left);
    }
    else {
        cur_node->right = add_leaf(insert_data, cur_node->right);
    }
    return (cur_node);
}
template<typename T>
void Node<T>::delete_branch(Node<T> *deleting_node)
{

    if (deleting_node != nullptr) {
        delete_branch(deleting_node->left);
        delete_branch(deleting_node->right);
        delete deleting_node;
    }
}
template<typename T>
Node<T> *Node<T>::delete_node(Node<T> *node, const T &variable_of_interest)
{
    if (node == nullptr) {
        return node;
    }
    if (node->data > variable_of_interest) {
        node->left = delete_node(node->left, variable_of_interest);
    }
    else if (node->data < variable_of_interest) {
        node->right = delete_node(node->right, variable_of_interest);
    }
    else {
        Node<T> *temp_node;
        if (node->right == nullptr) {

            temp_node = node->left;
        }
        else {
            Node<T> *node_pointer = node->right;
            if (node_pointer->left == nullptr) {
                node_pointer->left = node->left;
                temp_node = node_pointer;
            }
            else {
                Node<T> *left_min_node = node_pointer->left;
                while (left_min_node->left != nullptr) {
                    node_pointer = left_min_node;
                    left_min_node = node_pointer->left;
                }
                node_pointer->left = left_min_node->right;
                left_min_node->left = node->left;
                left_min_node->right = node->right;
                temp_node = left_min_node;
            }
        }

        delete node;
        return temp_node;
    }
    return node;
}

