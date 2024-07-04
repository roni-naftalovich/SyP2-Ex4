#ifndef TREE_ITERATORS_HPP
#define TREE_ITERATORS_HPP

#include "tree.hpp"

template <typename T>
class Tree<T>::PreOrderIterator {
private:
    std::stack<TreeNode<T>*> nodeStack;

public:
    explicit PreOrderIterator(TreeNode<T>* root);
    bool operator!=(const PreOrderIterator& other) const;
    TreeNode<T>* operator*();
    PreOrderIterator& operator++();
};

template <typename T>
class Tree<T>::PostOrderIterator {
private:
    std::stack<TreeNode<T>*> nodeStack1, nodeStack2;

public:
    explicit PostOrderIterator(TreeNode<T>* root);
    bool operator!=(const PostOrderIterator& other) const;
    TreeNode<T>* operator*();
    PostOrderIterator& operator++();
};

template <typename T>
class Tree<T>::InOrderIterator {
private:
    std::stack<TreeNode<T>*> nodeStack;
    TreeNode<T>* currentNode;

public:
    explicit InOrderIterator(TreeNode<T>* root);
    bool operator!=(const InOrderIterator& other) const;
    TreeNode<T>* operator*();
    InOrderIterator& operator++();
};

template <typename T>
class Tree<T>::BFSIterator {
private:
    std::queue<TreeNode<T>*> nodeQueue;

public:
    explicit BFSIterator(TreeNode<T>* root);
    bool operator!=(const BFSIterator& other) const;
    TreeNode<T>* operator*();
    BFSIterator& operator++();
};

template <typename T>
class Tree<T>::DFSIterator {
private:
    std::stack<TreeNode<T>*> nodeStack;

public:
    explicit DFSIterator(TreeNode<T>* root);
    bool operator!=(const DFSIterator& other) const;
    TreeNode<T>* operator*();
    DFSIterator& operator++();
};

template <typename T>
class Tree<T>::HeapIterator {
private:
    std::vector<TreeNode<T>*> heapNodes;
    size_t index;

    void heapify(TreeNode<T>* node);

public:
    explicit HeapIterator(TreeNode<T>* root);
    bool operator!=(const HeapIterator& other) const;
    TreeNode<T>* operator*();
    HeapIterator& operator++();
};

#include "tree_iterators.tpp"  // Include the implementation of iterators

#endif // TREE_ITERATORS_HPP
