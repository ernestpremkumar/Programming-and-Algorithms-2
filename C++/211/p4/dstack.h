#ifndef DSTACK_H
#define DSTACK_H
#include <iostream>

class dStack {

public:
  dStack();
  ~dStack();
  void push(double);
  bool pop(double &value);
  bool empty();

private:
  class Node *{
  public:
    Node(double value, Node *node) {
      m_value = value; m_next = node;
    }
    double m_value;
    Node *m_next;
  };
  Node *m_head;
  int m_length;
};
#endif
