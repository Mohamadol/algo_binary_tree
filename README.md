# Binary Search Tree (C++)

A lightweight **Binary Search Tree (BST)** implementation in modern C++ for educational and testing purposes.  
This project demonstrates recursive and iterative insertion, different traversal orders, and height computation.

---

## Features

- **Insertion**
  - Supports both iterative and recursive versions
  - Ignores duplicate values automatically
- **Traversals**
  - Inorder, Preorder, and Postorder
- **Height calculation**
  - Empty tree → `-1`
  - Single node → `0`
  - Updates correctly as nodes are inserted
- **Basic unit testing harness**
  - Verifies insertion, traversal, and height behaviors
  - Prints clear PASS/FAIL summaries

---

## Project Structure

```
project_root/
├── src/
│   ├── binary_tree.hpp     # Node + BinaryTree class definitions
│   └── main.cpp            # Test harness with multiple test cases
├── build/                  # Build artifacts (ignored by git)
├── .gitignore
└── README.md
```

---

## ⚙️ Build Instructions

### 🔹 Using `g++` directly

```bash
g++ -std=c++17 -Wall -Wextra -O2 -o main src/main.cpp
./main
```

### Using CMake (optional)

```bash
mkdir -p build && cd build
cmake ..
make
./main
```

---

## Example Output

When all tests pass, you should see something like:

```
Test summary:
---------------------------------
✅ test_insert PASSED
✅ test_height_basic PASSED
✅ test_height_skewed PASSED
---------------------------------
🎉 ALL TESTS PASSED
```

If a test fails, the expected and actual results will be printed to help debugging.

---

## Example Usage

```cpp
#include "binary_tree.hpp"
#include <iostream>

int main() {
    BinaryTree tree;

    // Insert values
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(1);
    tree.insert(4);

    // Inorder traversal prints sorted order
    auto inorder = tree.traverse("inorder");

    std::cout << "Inorder: ";
    for (int v : inorder)
        std::cout << v << " ";
    std::cout << std::endl;

    std::cout << "Tree height: " << tree.get_height() << std::endl;
    return 0;
}
```

**Output:**
```
Inorder: 1 3 4 5 8
Tree height: 2
```

---

## 🧾 Notes

- This implementation focuses on clarity and correctness, not balancing.
- You can extend it with:
  - Recursive deletion
  - Node-level height tracking
  - Balancing (e.g., AVL or Red–Black Tree)

---

## 🪪 License

**MIT License**  
You are free to use, modify, and distribute this project for educational or personal use.  
Attribution is appreciated but not required.

---

## 💬 Author

Developed as a learning exercise in C++ data structures.  
Feel free to contribute improvements or report issues!
