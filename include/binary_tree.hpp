#pragma once

#include <vector>
#include <stdexcept>
#include <cstddef>

class Node
{
    Node *right_;
    Node *left_;
    int value_;

public:
    explicit Node(int value) : right_(nullptr), left_(nullptr), value_(value) {};

    inline Node *get_right() { return right_; };
    inline void set_right(Node *right) { right_ = right; }

    inline Node *get_left() { return left_; }
    inline void set_left(Node *left) { left_ = left; }

    inline int get_value() { return value_; };
    inline void set_value(int value) { value_ = value; };
};

/**
 * Simple Binary Search Tree (BST) for practice.
 * Policy:
 *   - insert(x): ignores duplicates (does not insert a second copy)
 *   - contains(x): true if value present
 *   - traversals: inorder, preorder, postorder
 *   - height(): empty tree = -1, single node = 0
 *   - size(): number of nodes
 */

class BinaryTree
{
public:
    BinaryTree() : root_(nullptr), nodes_(0) {};

    // --> main methods
    void insert(int value);
    std::vector<int> traverse(const std::string &order = "inorder");
    int height() const;

    // --> setters and getter
    Node *get_root() const { return root_; };
    void set_root(Node *root) { root_ = root; };
    int get_nodes() const { return nodes_; };
    void set_nodes(int nodes) { nodes_ = nodes; };

private:
    // --> private helper methods
    void traverse(Node *node, std::vector<int> &result, const std::string &order);
    void insert(Node *node, int value);
    int height(Node *node) const;

    // --> private data
    Node *root_;
    int nodes_;
};