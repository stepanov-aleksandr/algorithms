#ifndef BST_H
#define BST_H

#include "headers.h"

namespace bst {
struct TreeNode {
  struct TreeNode *leftChild;
  struct TreeNode *rightChild;
  friend bool operator<(const TreeNode &lhs, const TreeNode &rhs);
  TreeNode(int val);
  int val_;
};

class BST {
 public:
  TreeNode *root_node_;
  int size_;
  BST(int key);
  void Insert(int val);
  void Erase(int val);
  size_t Size() const;
  void Print() const;
  bool Find(int val) const;
  size_t Traverse(TreeNode *root);
  std::pair<TreeNode *, size_t> Traverse_(TreeNode *root);

 private:
  void DeleteTree(TreeNode *current_node);
};
}  // namespace bst

#endif  // BST_H
