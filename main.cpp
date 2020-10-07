#include "bst.h"
#include "function.h"

using namespace function;
using namespace bst;

int main() {
  BST bst(5);
  bst.Insert(3);
  bst.Insert(6);
  bst.Insert(8);
  bst.Insert(9);
  bst.Insert(15);
  bst.Insert(10);
  bst.Insert(3);
  bst.Insert(1);
  bst.Insert(4);
  bst.Insert(2);
  auto root = bst.Traverse(bst.root_node_);

  return 0;
}
