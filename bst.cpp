#include "bst.h"

namespace bst {
BST::BST(int key) {
  root_node_ = new TreeNode(key);
  size_ = 1;
}

void BST::Insert(int val) {
  TreeNode *curr = root_node_;
  while (curr != nullptr && curr->val_ != val) {
    if (curr->val_ > val && curr->leftChild == nullptr) {
      curr->leftChild = new TreeNode(val);
      ++size_;
      return;
    }
    if (curr->val_ < val && curr->rightChild == nullptr) {
      curr->rightChild = new TreeNode(val);
      ++size_;
      return;
    }
    if (curr->val_ > val)
      curr = curr->leftChild;
    else
      curr = curr->rightChild;
  }
}

bool BST::Find(int val) const {
  TreeNode *curr = root_node_;
  while (curr != nullptr && curr->val_ != val) {
    if (curr->val_ > val)
      curr = curr->leftChild;
    else
      curr = curr->rightChild;
  }
  return curr != nullptr;
}

size_t BST::Traverse(TreeNode *root) {
  static int l_len = 0;
  static int r_len = 0;
  if (root == nullptr) {
    return (0);
  } else {
    l_len = Traverse(root->leftChild);
    r_len = Traverse(root->rightChild);
    if (l_len > r_len)
      return (l_len + 1);
    else
      return (r_len + 1);
  }
  return 0;
}

std::pair<TreeNode *, size_t> BST::Traverse_(TreeNode *root) {
  static int l_len = 0;
  static int r_len = 0;
  static TreeNode *ret;
  if (root == nullptr) {
    return {};
  } else {
    auto l_ret = Traverse_(root->leftChild);
    auto r_ret = Traverse_(root->rightChild);
    if (l_ret.second > r_ret.second) {
      l_len = l_ret.second + 1;
      return l_ret;
    } else {
      r_len = r_ret.second + 1;
      return r_ret;
    }
  }
}

void BST::DeleteTree(TreeNode *current_node) {
  if (current_node != nullptr) {
    DeleteTree(current_node->rightChild);
    DeleteTree(current_node->leftChild);
    delete current_node;
  }
}

bool operator<(const TreeNode &lhs, const TreeNode &rhs) {
  if (lhs.val_ < rhs.val_) {
    return true;
  } else {
    return false;
  }
}

TreeNode::TreeNode(int val) {
  val_ = val;
  rightChild = nullptr;
  leftChild = nullptr;
}

}  // namespace bst
