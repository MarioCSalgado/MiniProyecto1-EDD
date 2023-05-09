#ifndef LISTARR_H
#define LISTARR_H
#include "ListArrADT.h"
#include "ListArrNode.h"

class ListArr: public ListArrADT {
private:
  int b;
  ListArrNode *head;
  ListArrNode *tail;
  int n;

public:
  ListArr(int b);

  int size();
  void insert_left(int v);
  void insert_right(int v);
  void insert(int v, int i);
  void print();
  bool find(int v);
  int delete_left();
  int delete_right();
};

#endif