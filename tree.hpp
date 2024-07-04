#ifndef TREE_HPP
#define TREE_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <stdexcept>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

template <typename T>
class TreeNode {
public:
    T key;
    std::vector<TreeNode<T>*> children;

    explicit TreeNode(T key);
    void addChild(TreeNode<T>* child);
    T get_value() const;
};

template <typename T>
class Tree {
private:
    TreeNode<T>* root;
    int k;

    void deleteTree(TreeNode<T>* node);
    void renderTree(SDL_Renderer* renderer, TTF_Font* font, TreeNode<T>* node, int x, int y, int offsetX, int offsetY) const;

public:
    explicit Tree(int k = 2);
    ~Tree();
    void add_root(const T& key);
    void add_sub_node(TreeNode<T>* parent, const T& key);
    TreeNode<T>* getRoot();

    // Declare iterator classes
    class PreOrderIterator;
    class PostOrderIterator;
    class InOrderIterator;
    class BFSIterator;
    class DFSIterator;
    class HeapIterator;

    // Iterator methods
    PreOrderIterator begin_pre_order();
    PreOrderIterator end_pre_order();
    PostOrderIterator begin_post_order();
    PostOrderIterator end_post_order();
    InOrderIterator begin_in_order();
    InOrderIterator end_in_order();
    BFSIterator begin_bfs_scan();
    BFSIterator end_bfs_scan();
    DFSIterator begin_dfs_scan();
    DFSIterator end_dfs_scan();
    HeapIterator begin_heap();
    HeapIterator end_heap();

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Tree<U>& tree);
};

#include "tree.tpp"
#include "tree_iterators.hpp"  // Ensure the iterators are included

#endif // TREE_HPP
