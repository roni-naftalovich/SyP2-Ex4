#include "tree.hpp"

template <typename T>
TreeNode<T>::TreeNode(T key) : key(key) {}

template <typename T>
void TreeNode<T>::addChild(TreeNode<T>* child) {
    children.push_back(child);
}

template <typename T>
T TreeNode<T>::get_value() const {
    return key;
}

template <typename T>
Tree<T>::Tree(int k) : root(nullptr), k(k) {}

template <typename T>
Tree<T>::~Tree() {
    deleteTree(root);
}

template <typename T>
void Tree<T>::deleteTree(TreeNode<T>* node) {
    if (node) {
        for (auto& child : node->children) {
            deleteTree(child);
        }
        delete node;
    }
}

template <typename T>
void Tree<T>::add_root(const T& key) {
    if (root) {
        root->key = key;
    } else {
        root = new TreeNode<T>(key);
    }
}

template <typename T>
void Tree<T>::add_sub_node(TreeNode<T>* parent, const T& key) {
    if (parent->children.size() >= k) {
        throw std::out_of_range("Number of children exceeds the allowed maximum");
    }
    TreeNode<T>* child = new TreeNode<T>(key);
    parent->addChild(child);
}

template <typename T>
TreeNode<T>* Tree<T>::getRoot() {
    return root;
}

template <typename T>
typename Tree<T>::PreOrderIterator Tree<T>::begin_pre_order() {
    return PreOrderIterator(root);
}

template <typename T>
typename Tree<T>::PreOrderIterator Tree<T>::end_pre_order() {
    return PreOrderIterator(nullptr);
}

template <typename T>
typename Tree<T>::PostOrderIterator Tree<T>::begin_post_order() {
    return PostOrderIterator(root);
}

template <typename T>
typename Tree<T>::PostOrderIterator Tree<T>::end_post_order() {
    return PostOrderIterator(nullptr);
}

template <typename T>
typename Tree<T>::InOrderIterator Tree<T>::begin_in_order() {
    return InOrderIterator(root);
}

template <typename T>
typename Tree<T>::InOrderIterator Tree<T>::end_in_order() {
    return InOrderIterator(nullptr);
}

template <typename T>
typename Tree<T>::BFSIterator Tree<T>::begin_bfs_scan() {
    return BFSIterator(root);
}

template <typename T>
typename Tree<T>::BFSIterator Tree<T>::end_bfs_scan() {
    return BFSIterator(nullptr);
}

template <typename T>
typename Tree<T>::DFSIterator Tree<T>::begin_dfs_scan() {
    return DFSIterator(root);
}

template <typename T>
typename Tree<T>::DFSIterator Tree<T>::end_dfs_scan() {
    return DFSIterator(nullptr);
}

template <typename T>
typename Tree<T>::HeapIterator Tree<T>::begin_heap() {
    return HeapIterator(root);
}

template <typename T>
typename Tree<T>::HeapIterator Tree<T>::end_heap() {
    return HeapIterator(nullptr);
}
