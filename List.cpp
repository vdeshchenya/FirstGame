#include "List.h"

Node::Node(const BlockType &type_, const int &x) : data(type_, x), next(nullptr), prev(nullptr) {};