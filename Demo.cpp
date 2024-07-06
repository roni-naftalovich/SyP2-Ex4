// Roni Naftalovich 319049060, roni100400100400@gmail.com
#include "tree.hpp"

int main() {
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(1.1);

    TreeNode<double>* root_node = tree.getRoot();
    tree.add_sub_node(root_node, 1.2);
    tree.add_sub_node(root_node, 1.3);

    TreeNode<double>* n1 = root_node->children[0];
    TreeNode<double>* n2 = root_node->children[1];

    tree.add_sub_node(n1, 1.4);
    tree.add_sub_node(n1, 1.5);
    tree.add_sub_node(n2, 1.6);

    //The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    std::cout << "Pre-Order: ";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
        std::cout << (*node)->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "Post-Order: ";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
        std::cout << (*node)->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "In-Order: ";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
        std::cout << (*node)->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "BFS: ";
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
        std::cout << (*node)->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "DFS: ";
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
        std::cout << (*node)->get_value() << " ";
    }
    std::cout << std::endl;

    std::cout << "Heap: ";
    for (auto heapIt = tree.begin_heap(); heapIt != tree.end_heap(); ++heapIt) {
        std::cout << (*heapIt)->get_value() << " ";
    }
    std::cout << std::endl;
    std::cout << tree;

        // Create a 3-ary tree with integer keys
    Tree<int> tree1(3);

    // Add the root node
    tree1.add_root(1);

    // Get the root node
    TreeNode<int>* root_node1 = tree1.getRoot();

    // Add children to the root node
    tree1.add_sub_node(root_node1, 2);
    tree1.add_sub_node(root_node1, 3);
    tree1.add_sub_node(root_node1, 4);

    // Get the children of the root node
    TreeNode<int>* n11 = root_node1->children[0];
    TreeNode<int>* n21 = root_node1->children[1];
    TreeNode<int>* n31 = root_node1->children[2];

    // Add children to the first child of the root node
    tree1.add_sub_node(n11, 5);
    tree1.add_sub_node(n11, 6);
    tree1.add_sub_node(n11, 7);

    // Add children to the second child of the root node
    tree1.add_sub_node(n21, 8);
    tree1.add_sub_node(n21, 9);

    // Add children to the third child of the root node
    tree1.add_sub_node(n31, 10);
    tree1.add_sub_node(n31, 11);
    //tree1.add_sub_node(n31, 12);

    // The tree should look like this:
    /**
     *          1
     *      /   |   \
     *     2    3    4
     *    /|\  / \  /|\
     *   5 6 7 8  9 10 11 12
     */

    std::cout << tree1;

    return 0;
}
