// Roni Naftalovich 319049060, roni100400100400@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "tree_iterators.hpp"
#include "Complex.hpp"

TEST_CASE("Tree with double") {
    Tree<double> tree;
    tree.add_root(1.1);
    TreeNode<double>* root = tree.getRoot();
    tree.add_sub_node(root, 2.2);
    tree.add_sub_node(root, 3.3);
    
    TreeNode<double>* left = root->children[0];
    TreeNode<double>* right = root->children[1];
    
    REQUIRE(tree.getRoot()->key == 1.1);
    REQUIRE(left->key == 2.2);
    REQUIRE(right->key == 3.3);

    // Try to add more than 2 children to the root node (k=2)
    CHECK_THROWS_AS(tree.add_sub_node(root, 4.4), std::out_of_range);

    std::vector<double> pre_order = {1.1, 2.2, 3.3};
    std::vector<double> post_order = {2.2, 3.3, 1.1};
    std::vector<double> in_order = {2.2, 1.1, 3.3};
    std::vector<double> bfs_order = {1.1, 2.2, 3.3};
    std::vector<double> dfs_order = {1.1, 2.2, 3.3};
    
    int index = 0;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        REQUIRE((*it)->key == pre_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        REQUIRE((*it)->key == post_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        REQUIRE((*it)->key == in_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        REQUIRE((*it)->key == bfs_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        REQUIRE((*it)->key == dfs_order[index++]);
    }
}

TEST_CASE("Tree with strings") {
    Tree<std::string> tree;
    tree.add_root("root");
    TreeNode<std::string>* root = tree.getRoot();
    tree.add_sub_node(root, "left");
    tree.add_sub_node(root, "right");
    
    TreeNode<std::string>* left = root->children[0];
    TreeNode<std::string>* right = root->children[1];
    
    REQUIRE(tree.getRoot()->key == "root");
    REQUIRE(left->key == "left");
    REQUIRE(right->key == "right");

    std::vector<std::string> pre_order = {"root", "left", "right"};
    std::vector<std::string> post_order = {"left", "right", "root"};
    std::vector<std::string> in_order = {"left", "root", "right"};
    std::vector<std::string> bfs_order = {"root", "left", "right"};
    std::vector<std::string> dfs_order = {"root", "left", "right"};
    
    int index = 0;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        REQUIRE((*it)->key == pre_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        REQUIRE((*it)->key == post_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        REQUIRE((*it)->key == in_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        REQUIRE((*it)->key == bfs_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        REQUIRE((*it)->key == dfs_order[index++]);
    }
    std::cout << tree;
}

TEST_CASE("Tree with char") {
    Tree<char> tree;
    tree.add_root('A');
    TreeNode<char>* root = tree.getRoot();
    tree.add_sub_node(root, 'B');
    tree.add_sub_node(root, 'C');
    
    TreeNode<char>* left = root->children[0];
    TreeNode<char>* right = root->children[1];
    
    REQUIRE(tree.getRoot()->key == 'A');
    REQUIRE(left->key == 'B');
    REQUIRE(right->key == 'C');

    std::vector<char> pre_order = {'A', 'B', 'C'};
    std::vector<char> post_order = {'B', 'C', 'A'};
    std::vector<char> in_order = {'B', 'A', 'C'};
    std::vector<char> bfs_order = {'A', 'B', 'C'};
    std::vector<char> dfs_order = {'A', 'B', 'C'};
    
    int index = 0;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        REQUIRE((*it)->key == pre_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        REQUIRE((*it)->key == post_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        REQUIRE((*it)->key == in_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        REQUIRE((*it)->key == bfs_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        REQUIRE((*it)->key == dfs_order[index++]);
    }
}

TEST_CASE("Tree with complex") {
    Tree<Complex> tree;
    tree.add_root(Complex(1.1, 2.2));
    TreeNode<Complex>* root = tree.getRoot();
    tree.add_sub_node(root, Complex(3.3, 4.4));
    tree.add_sub_node(root, Complex(5.5, 6.6));
    
    TreeNode<Complex>* left = root->children[0];
    TreeNode<Complex>* right = root->children[1];
    
    REQUIRE(tree.getRoot()->key == Complex(1.1, 2.2));
    REQUIRE(left->key == Complex(3.3, 4.4));
    REQUIRE(right->key == Complex(5.5, 6.6));

    // Check Complex operators
    REQUIRE(Complex(1.1, 2.2) == Complex(1.1, 2.2));
    REQUIRE(Complex(1.1, 2.2) != Complex(3.3, 4.4));
    REQUIRE(Complex(1.1, 2.2) < Complex(3.3, 4.4));
    REQUIRE(Complex(5.5, 6.6) > Complex(5.5, 4.4));

    std::vector<Complex> pre_order = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(5.5, 6.6)};
    std::vector<Complex> post_order = {Complex(3.3, 4.4), Complex(5.5, 6.6), Complex(1.1, 2.2)};
    std::vector<Complex> in_order = {Complex(3.3, 4.4), Complex(1.1, 2.2), Complex(5.5, 6.6)};
    std::vector<Complex> bfs_order = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(5.5, 6.6)};
    std::vector<Complex> dfs_order = {Complex(1.1, 2.2), Complex(3.3, 4.4), Complex(5.5, 6.6)};
    
    int index = 0;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        REQUIRE((*it)->key == pre_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        REQUIRE((*it)->key == post_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        REQUIRE((*it)->key == in_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        REQUIRE((*it)->key == bfs_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        REQUIRE((*it)->key == dfs_order[index++]);
    }
}

TEST_CASE("Tree with integers") {
    Tree<int> tree;
    tree.add_root(1);
    TreeNode<int>* root = tree.getRoot();
    tree.add_sub_node(root, 2);
    tree.add_sub_node(root, 3);
    
    TreeNode<int>* left = root->children[0];
    TreeNode<int>* right = root->children[1];
    
    REQUIRE(tree.getRoot()->key == 1);
    REQUIRE(left->key == 2);
    REQUIRE(right->key == 3);

    std::vector<int> pre_order = {1, 2, 3};
    std::vector<int> post_order = {2, 3, 1};
    std::vector<int> in_order = {2, 1, 3};
    std::vector<int> bfs_order = {1, 2, 3};
    std::vector<int> dfs_order = {1, 2, 3};
    
    int index = 0;
    for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
        REQUIRE((*it)->key == pre_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_post_order(); it != tree.end_post_order(); ++it) {
        REQUIRE((*it)->key == post_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_in_order(); it != tree.end_in_order(); ++it) {
        REQUIRE((*it)->key == in_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it) {
        REQUIRE((*it)->key == bfs_order[index++]);
    }
    
    index = 0;
    for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it) {
        REQUIRE((*it)->key == dfs_order[index++]);
    }
}
