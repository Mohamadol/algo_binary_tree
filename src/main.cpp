#include "binary_tree.hpp"
#include <iostream>
#include <vector>

static void print_vec(const std::vector<int> &v)
{
    for (int x : v)
        std::cerr << x << " ";
}

// ------- Tests --------

bool test_insert()
{
    BinaryTree tree;

    // Insert values (with one duplicate)
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);
    tree.insert(3); // duplicate, ignored

    // Expected inorder sequence (sorted, no duplicates)
    std::vector<int> expected = {1, 3, 4, 5, 7, 8, 9};
    std::vector<int> inorder = tree.traverse("inorder");

    if (inorder != expected)
    {
        std::cerr << "❌ test_insert FAILED\nExpected: ";
        print_vec(expected);
        std::cerr << "\nGot: ";
        print_vec(inorder);
        std::cerr << std::endl;
        return false;
    }
    return true;
}

// Height of empty = -1; single node = 0; above shape should be 2
bool test_height_basic()
{
    BinaryTree tree;

    // Empty
    if (tree.height() != -1)
    {
        std::cerr << "❌ test_height_basic FAILED: empty height expected -1, got "
                  << tree.height() << "\n";
        return false;
    }

    // One node
    tree.insert(5);
    if (tree.height() != 0)
    {
        std::cerr << "❌ test_height_basic FAILED: single-node height expected 0, got "
                  << tree.height() << "\n";
        return false;
    }

    // Build a balanced-ish small tree
    tree.insert(3);
    tree.insert(8);
    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);
    // Height should be 2 (edges): root(5) -> (3/8) -> (1/4/7/9)
    if (tree.height() != 2)
    {
        std::cerr << "❌ test_height_basic FAILED: height expected 2, got "
                  << tree.height() << "\n";
        return false;
    }

    // Duplicate should NOT change height
    tree.insert(3); // duplicate
    if (tree.height() != 2)
    {
        std::cerr << "❌ test_height_basic FAILED: height changed after duplicate insert, got "
                  << tree.height() << "\n";
        return false;
    }

    return true;
}

// A skewed (ascending) insertion should yield height = n-1
bool test_height_skewed()
{
    BinaryTree t;

    // Empty
    if (t.height() != -1)
    {
        std::cerr << "❌ test_height_skewed FAILED: empty height expected -1, got "
                  << t.height() << "\n";
        return false;
    }

    // Insert ascending: 1,2,3,4 (degenerate right-leaning)
    t.insert(1);
    if (t.height() != 0)
    {
        std::cerr << "❌ test_height_skewed FAILED: after 1 insert height expected 0, got "
                  << t.height() << "\n";
        return false;
    }
    t.insert(2);
    if (t.height() != 1)
    {
        std::cerr << "❌ test_height_skewed FAILED: after 2 inserts height expected 1, got "
                  << t.height() << "\n";
        return false;
    }
    t.insert(3);
    if (t.height() != 2)
    {
        std::cerr << "❌ test_height_skewed FAILED: after 3 inserts height expected 2, got "
                  << t.height() << "\n";
        return false;
    }
    t.insert(4);
    if (t.height() != 3)
    {
        std::cerr << "❌ test_height_skewed FAILED: after 4 inserts height expected 3, got "
                  << t.height() << "\n";
        return false;
    }

    return true;
}

// ------- Main harness --------
int main()
{
    bool all_passed = true;

    bool insert_ok = test_insert();
    bool height_ok = test_height_basic();
    bool skewed_ok = test_height_skewed();

    std::cout << "\nTest summary:\n";
    std::cout << "---------------------------------\n";
    std::cout << (insert_ok ? "✅ test_insert PASSED\n" : "❌ test_insert FAILED\n");
    std::cout << (height_ok ? "✅ test_height_basic PASSED\n" : "❌ test_height_basic FAILED\n");
    std::cout << (skewed_ok ? "✅ test_height_skewed PASSED\n" : "❌ test_height_skewed FAILED\n");
    std::cout << "---------------------------------\n";

    all_passed = insert_ok && height_ok && skewed_ok;

    if (all_passed)
        std::cout << "🎉 ALL TESTS PASSED\n";
    else
        std::cout << "⚠️  SOME TESTS FAILED\n";

    return all_passed ? 0 : 1;
}
