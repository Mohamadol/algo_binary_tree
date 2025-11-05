#include "binary_tree.hpp"
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

static void expect_eq(const std::vector<int>& a, const std::vector<int>& b, const std::string& name) {
    if (a != b) {
        std::cerr << "FAIL: " << name << "\n  got:  ";
        for (auto v : a) std::cerr << v << " ";
        std::cerr << "\n  want: ";
        for (auto v : b) std::cerr << v << " ";
        std::cerr << "\n";
        std::abort();
    }
}

static void expect_true(bool cond, const std::string& name) {
    if (!cond) { std::cerr << "FAIL: " << name << "\n"; std::abort(); }
}

static void expect_eq_sz(std::size_t a, std::size_t b, const std::string& name) {
    if (a != b) {
        std::cerr << "FAIL: " << name << " got " << a << " want " << b << "\n";
        std::abort();
    }
}

static void test_empty_tree() {
    BinaryTree t;
    expect_eq_sz(t.size(), 0, "empty size");
    expect_eq(t.inorder(), {}, "empty inorder");
    expect_eq(t.preorder(), {}, "empty preorder");
    expect_eq(t.postorder(), {}, "empty postorder");
    expect_true(t.height() == -1, "empty height == -1");
    expect_true(!t.contains(42), "empty contains false");
}

static void test_inserts_and_traversals() {
    BinaryTree t;
    std::vector<int> vals = {7, 3, 9, 1, 5, 8, 10};
    for (int v : vals) t.insert(v);

    expect_eq_sz(t.size(), vals.size(), "size after inserts");

    expect_true(t.contains(1), "contains 1");
    expect_true(t.contains(10), "contains 10");
    expect_true(!t.contains(4), "does not contain 4");

    // Height for this shape should be 2
    expect_true(t.height() == 2, "height == 2");

    expect_eq(t.inorder(),   (std::vector<int>{1,3,5,7,8,9,10}), "inorder");
    expect_eq(t.preorder(),  (std::vector<int>{7,3,1,5,9,8,10}), "preorder");
    expect_eq(t.postorder(), (std::vector<int>{1,5,3,8,10,9,7}), "postorder");

    auto levels = t.level_order();
    // level order should be: [7], [3,9], [1,5,8,10]
    if (levels.size() != 3 ||
        levels[0] != std::vector<int>{7} ||
        levels[1] != std::vector<int>{3,9} ||
        levels[2] != std::vector<int>{1,5,8,10}) {
        std::cerr << "FAIL: level_order\n";
        std::abort();
    }
}

static void test_duplicates_ignored() {
    BinaryTree t;
    t.insert(5);
    t.insert(5);
    t.insert(5);
    expect_eq_sz(t.size(), 1, "duplicates ignored size=1");
    expect_eq(t.inorder(), std::vector<int>{5}, "duplicates inorder");
}

static void test_erase_optional() {
    BinaryTree t;
    for (int v : {5, 2, 8, 1, 3, 7, 9}) t.insert(v);
    expect_true(t.erase(2), "erase(2)");
    expect_eq(t.inorder(), (std::vector<int>{1,3,5,7,8,9}), "inorder after erase(2)");
    expect_true(!t.contains(2), "not contains(2)");

    expect_true(t.erase(5), "erase(5) [root with two children]");
    expect_eq(t.inorder(), (std::vector<int>{1,3,7,8,9}), "inorder after erase(5)");
    expect_true(!t.contains(5), "not contains(5)");

    expect_true(!t.erase(42), "erase missing returns false");
}

int main() {
    test_empty_tree();
    test_inserts_and_traversals();
    test_duplicates_ignored();

    // Optional (comment out if you haven’t implemented erase yet)
    test_erase_optional();

    std::cout << "All tests passed ✅\n";
    return 0;
}

