#include "tree.hpp"

int main() {
    // Tree<double> tree; // Binary tree that contains doubles.
    // tree.add_root(1.1);

    // TreeNode<double>* root_node = tree.getRoot();
    // tree.add_sub_node(root_node, 1.2);
    // tree.add_sub_node(root_node, 1.3);

    // TreeNode<double>* n1 = root_node->children[0];
    // TreeNode<double>* n2 = root_node->children[1];

    // tree.add_sub_node(n1, 1.4);
    // tree.add_sub_node(n1, 1.5);
    // tree.add_sub_node(n2, 1.6);

    // // The tree should look like:
    // /**
    //  *       root = 1.1
    //  *     /       \
    //  *    1.2      1.3
    //  *   /  \      /
    //  *  1.4  1.5  1.6
    //  */

    // std::cout << "Pre-Order: ";
    // for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
    //     std::cout << (*node)->get_value() << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Post-Order: ";
    // for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node) {
    //     std::cout << (*node)->get_value() << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "In-Order: ";
    // for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node) {
    //     std::cout << (*node)->get_value() << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "BFS: ";
    // for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node) {
    //     std::cout << (*node)->get_value() << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "DFS: ";
    // for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node) {
    //     std::cout << (*node)->get_value() << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Heap: ";
    // for (auto heapIt = tree.begin_heap(); heapIt != tree.end_heap(); ++heapIt) {
    //     std::cout << (*heapIt)->get_value() << " ";
    // }
    // std::cout << std::endl;
    // std::cout << tree;

    Tree<Complex> tree; // Binary tree that contains Complex numbers.
    tree.add_root(Complex(1.1, 2.2));

    TreeNode<Complex>* root_node = tree.getRoot();
    tree.add_sub_node(root_node, Complex(3.3, 4.4));
    tree.add_sub_node(root_node, Complex(5.5, 6.6));

    TreeNode<Complex>* n1 = root_node->children[0];
    TreeNode<Complex>* n2 = root_node->children[1];

    tree.add_sub_node(n1, Complex(7.7, 8.8));
    tree.add_sub_node(n1, Complex(9.9, 10.1));
    tree.add_sub_node(n2, Complex(11.11, 12.12));

    std::cout << tree;

    return 0;
}
