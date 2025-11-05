#include "binary_tree.hpp"

void BinaryTree::insert(int value)
{
    if (!get_root())
    {
        Node *new_node = new Node(value);
        set_root(new_node);
        set_nodes(1);
        return;
    }
    auto node = get_root();
    insert(node, value);
};

void BinaryTree::insert(Node *node, int value)
{
    bool go_left = value < node->get_value();
    bool go_right = value > node->get_value();
    if (go_left)
    {
        if (!node->get_left())
        {
            node->set_left(new Node(value));
            set_nodes(get_nodes() + 1);
        }
        else
        {
            insert(node->get_left(), value);
        }
    }
    else if (go_right)
    {
        if (!node->get_right())
        {
            node->set_right(new Node(value));
            set_nodes(get_nodes() + 1);
        }
        else
        {
            insert(node->get_right(), value);
        }
    }
    else
    {
        // Duplicate: ignore (policy)
        return;
    }
}

std::vector<int> BinaryTree::traverse(const std::string &order)
{
    std::vector<int> result;
    traverse(root_, result, order);
    return result;
}

void BinaryTree::traverse(Node *node, std::vector<int> &result, const std::string &order)
{
    if (!node)
        return;

    if (order == "preorder")
    {
        result.push_back(node->get_value());
        traverse(node->get_left(), result, order);
        traverse(node->get_right(), result, order);
    }
    else if (order == "inorder")
    {
        traverse(node->get_left(), result, order);
        result.push_back(node->get_value());
        traverse(node->get_right(), result, order);
    }
    else if (order == "postorder")
    {
        traverse(node->get_left(), result, order);
        traverse(node->get_right(), result, order);
        result.push_back(node->get_value());
    }
    else
    {
        throw std::invalid_argument("Invalid traversal order: " + order);
    }
}

int BinaryTree::height() const
{
    return height(get_root());
}

int BinaryTree::height(Node *node) const
{
    if (!node)
    {
        return -1;
    }
    int rh = height(node->get_right());
    int lh = height(node->get_left());
    return 1 + std::max(rh, lh);
}
