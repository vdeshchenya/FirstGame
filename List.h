#ifndef GMAE__LIST_H_
#define GMAE__LIST_H_
#include "Block.h"

struct Node {
  Node(const BlockType &type_, const int &x) : data(type_, x), next(nullptr), prev(nullptr) {}
  Block data;
  Node *next, *prev;
};

class List {
 public:
  Node *Start;
};

#endif //GMAE__LIST_H_
