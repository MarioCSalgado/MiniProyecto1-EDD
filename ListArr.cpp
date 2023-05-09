#include "ListArr.h"
#include <iostream>
#include <vector>

ListArr::ListArr(int b) : b(b), head(nullptr), tail(nullptr), n(0) {}

int ListArr::size() { return n; }

void ListArr::insert_left(int v) {
  if (head == nullptr || head->size == b) {
    ListArrNode *new_node = new ListArrNode(b);
    new_node->data[0] = v;
    new_node->size = 1;
    new_node->next = head;
    head = new_node;
    if (tail == nullptr) {
      tail = head;
    }
  } else {
    for (int i = head->size; i > 0; i--) {
      head->data[i] = head->data[i - 1];
    }
    head->data[0] = v;
    head->size++;
  }
  n++;
}

void ListArr::insert_right(int v) {
  if (tail == nullptr || tail->size == b) {
    ListArrNode *new_node = new ListArrNode(b);
    new_node->data[0] = v;
    new_node->size = 1;
    if (tail != nullptr) {
      tail->next = new_node;
    }
    tail = new_node;
    if (head == nullptr) {
      head = tail;
    }
  } else {
    tail->data[tail->size] = v;
    tail->size++;
  }
  n++;
}

void ListArr::insert(int v, int i) {
  if (i < 0 || i > n) {
    throw std::invalid_argument("Index out of bounds");
  }
  if (i == 0) {
    insert_left(v);
  } else if (i == n) {
    insert_right(v);
  } else {
    ListArrNode *current = head;
    int j = i;
    while (j >= current->size) {
      j -= current->size;
      current = current->next;
    }
    if (current->size == b) {
      ListArrNode *new_node = new ListArrNode(b);
      for (int k = 0; k < j; k++) {
        new_node->data[k] = current->data[k];
      }
      new_node->data[j] = v;
      for (int k = j + 1; k <= b; k++) {
        new_node->data[k] = current->data[k - 1];
      }
      new_node->size = b + 1;
      new_node->next = current->next;
      current->next = new_node;

      current->size -= b - j;

      for (int k = 0; k < current->size; k++) {
        current->data[k] = current->data[b - j + k];
      }

      if (current == tail) {
        tail = new_node;
      }
    } else {
      for (int k = current->size; k > j; k--) {
        current->data[k] = current->data[k - 1];
      }
      current->data[j] = v;
      current->size++;
    }
    n++;
  }
}

void ListArr::print() {
  ListArrNode *current = head;
  while (current != nullptr) {
    for (int i = 0; i < current->size; i++) {
      std::cout << current->data[i] << " ";
    }
    current = current->next;
  }
  std::cout << std::endl;
}

bool ListArr::find(int v) {
  ListArrNode *current = head;
  while (current != nullptr) {
    for (int i = 0; i < current->size; i++) {
      if (current->data[i] == v) {
        return true;
      }
    }
    current = current->next;
  }
  return false;
}

int ListArr::delete_left() {
  if (head == nullptr) {
    throw std::runtime_error("ListArr vacia");
  }
  int v = head->data[0];
  for (int i = 0; i < head->size - 1; i++) {
    head->data[i] = head->data[i + 1];
  }
  head->size--;
  if (head->size == 0) {
    ListArrNode *temp = head;
    head = head->next;
    delete temp;
    if (head == nullptr) {
      tail = nullptr;
    }
  }
  n--;
  return v;
}

int ListArr::delete_right() {
  if (tail == nullptr) {
    throw std::runtime_error("ListArr vacia");
  }
  int v = tail->data[tail->size - 1];
  tail->size--;
  if (tail->size == 0) {
    if (head == tail) {
      delete tail;
      head = nullptr;
      tail = nullptr;
    } else {
      ListArrNode *current = head;
      while (current->next != tail) {
        current = current->next;
      }
      current->next = nullptr;
      delete tail;
      tail = current;
    }
  }
  n--;
  return v;
}