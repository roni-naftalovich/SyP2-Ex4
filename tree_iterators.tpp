#include "tree_iterators.hpp"

// PreOrderIterator
template <typename T>
Tree<T>::PreOrderIterator::PreOrderIterator(TreeNode<T>* root) {
    if (root) nodeStack.push(root);
}

template <typename T>
bool Tree<T>::PreOrderIterator::operator!=(const PreOrderIterator& other) const {
    return !nodeStack.empty();
}

template <typename T>
TreeNode<T>* Tree<T>::PreOrderIterator::operator*() {
    return nodeStack.top();
}

template <typename T>
typename Tree<T>::PreOrderIterator& Tree<T>::PreOrderIterator::operator++() {
    TreeNode<T>* currentNode = nodeStack.top();
    nodeStack.pop();
    for (auto it = currentNode->children.rbegin(); it != currentNode->children.rend(); ++it) {
        nodeStack.push(*it);
    }
    return *this;
}

// PostOrderIterator
template <typename T>
Tree<T>::PostOrderIterator::PostOrderIterator(TreeNode<T>* root) {
    if (root) {
        nodeStack1.push(root);
        while (!nodeStack1.empty()) {
            TreeNode<T>* currentNode = nodeStack1.top();
            nodeStack1.pop();
            nodeStack2.push(currentNode);
            for (auto& child : currentNode->children) {
                nodeStack1.push(child);
            }
        }
    }
}

template <typename T>
bool Tree<T>::PostOrderIterator::operator!=(const PostOrderIterator& other) const {
    return !nodeStack2.empty();
}

template <typename T>
TreeNode<T>* Tree<T>::PostOrderIterator::operator*() {
    return nodeStack2.top();
}

template <typename T>
typename Tree<T>::PostOrderIterator& Tree<T>::PostOrderIterator::operator++() {
    nodeStack2.pop();
    return *this;
}

// InOrderIterator
template <typename T>
Tree<T>::InOrderIterator::InOrderIterator(TreeNode<T>* root) : currentNode(root) {
    while (currentNode) {
        nodeStack.push(currentNode);
        currentNode = currentNode->children.empty() ? nullptr : currentNode->children[0];
    }
}

template <typename T>
bool Tree<T>::InOrderIterator::operator!=(const InOrderIterator& other) const {
    return !nodeStack.empty();
}

template <typename T>
TreeNode<T>* Tree<T>::InOrderIterator::operator*() {
    return nodeStack.top();
}

template <typename T>
typename Tree<T>::InOrderIterator& Tree<T>::InOrderIterator::operator++() {
    TreeNode<T>* node = nodeStack.top();
    nodeStack.pop();
    if (!node->children.empty()) {
        currentNode = node->children.size() > 1 ? node->children[1] : nullptr;
        while (currentNode) {
            nodeStack.push(currentNode);
            currentNode = currentNode->children.empty() ? nullptr : currentNode->children[0];
        }
    }
    return *this;
}

// BFSIterator
template <typename T>
Tree<T>::BFSIterator::BFSIterator(TreeNode<T>* root) {
    if (root) nodeQueue.push(root);
}

template <typename T>
bool Tree<T>::BFSIterator::operator!=(const BFSIterator& other) const {
    return !nodeQueue.empty();
}

template <typename T>
TreeNode<T>* Tree<T>::BFSIterator::operator*() {
    return nodeQueue.front();
}

template <typename T>
typename Tree<T>::BFSIterator& Tree<T>::BFSIterator::operator++() {
    TreeNode<T>* currentNode = nodeQueue.front();
    nodeQueue.pop();
    for (auto& child : currentNode->children) {
        nodeQueue.push(child);
    }
    return *this;
}

// DFSIterator
template <typename T>
Tree<T>::DFSIterator::DFSIterator(TreeNode<T>* root) {
    if (root) nodeStack.push(root);
}

template <typename T>
bool Tree<T>::DFSIterator::operator!=(const DFSIterator& other) const {
    return !nodeStack.empty();
}

template <typename T>
TreeNode<T>* Tree<T>::DFSIterator::operator*() {
    return nodeStack.top();
}

template <typename T>
typename Tree<T>::DFSIterator& Tree<T>::DFSIterator::operator++() {
    TreeNode<T>* currentNode = nodeStack.top();
    nodeStack.pop();
    for (auto it = currentNode->children.rbegin(); it != currentNode->children.rend(); ++it) {
        nodeStack.push(*it);
    }
    return *this;
}

// HeapIterator
template <typename T>
Tree<T>::HeapIterator::HeapIterator(TreeNode<T>* root) : index(0) {
    heapify(root);
    std::make_heap(heapNodes.begin(), heapNodes.end(), [](TreeNode<T>* a, TreeNode<T>* b) {
        return a->key > b->key;
    });
}

template <typename T>
void Tree<T>::HeapIterator::heapify(TreeNode<T>* node) {
    if (!node) return;
    heapNodes.push_back(node);
    for (auto& child : node->children) {
        heapify(child);
    }
}

template <typename T>
bool Tree<T>::HeapIterator::operator!=(const HeapIterator& other) const {
    return index < heapNodes.size();
}

template <typename T>
TreeNode<T>* Tree<T>::HeapIterator::operator*() {
    return heapNodes[index];
}

template <typename T>
typename Tree<T>::HeapIterator& Tree<T>::HeapIterator::operator++() {
    ++index;
    return *this;
}
