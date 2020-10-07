#ifndef LIST_H
#define LIST_H

#include "headers.h"

namespace list {

typedef int SomeDataType;

struct List {
  List() { payload_ = 0; }
  List(int payload) : payload_(payload) {}
  struct List *next{nullptr};
  SomeDataType payload_{0};
  void Add(int i);
  void Remove(List *list);
  size_t SizeList(List *list) const;
};

}  // namespace list

#endif  // LIST_H
