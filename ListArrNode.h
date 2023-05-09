#ifndef LISTARRNODE_H
#define LISTARRNODE_H

#include <vector>

class ListArrNode {
public:
  int b;
  std::vector<int> data;
  int size;
  ListArrNode *next;

  ListArrNode(int b);
};

#endif