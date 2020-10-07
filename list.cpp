#include "list.h"

namespace list {

void List::Add(int i) {
  if (next == nullptr) {
    next = new List;
    next->payload_ = i;
  } else {
    next->Add(i);
  }
}

void List::Remove(List* list) {
  static auto ptr = list;
  if (nullptr == list) return;
  if (0 == list->payload_ % 5) {
    ptr->next = list->next;
    delete list;
    Remove(ptr->next);
  } else {
    ptr = list;
    Remove(list->next);
  }
}

size_t List::SizeList(List* list) const {
  if (list->next == nullptr) return 1;
  return 1 + SizeList(list->next);
}
}  // namespace list
