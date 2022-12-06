#include <iostream>
using namespace std;

template <typename N>
class Node
{
public:
  N value;
  Node *prev;
  Node *next;

  Node(N val)
  {
    this->value = val;
    this->next = NULL;
    this->prev = NULL;
  }
};

template <typename S>
class Stack
{
  Node<S> *head;
  Node<S> *tail;
  int count = 0;

public:
  Stack()
  {
    this->head = NULL;
    this->tail = NULL;
  }
  // push
  void push(S val)
  {
    Node<S> *newNode = new Node<S>(val);
    if (this->head == NULL)
    {
      head = tail = newNode;
      this->count++;
      return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    this->count++;
  };
  // pop
  S pop()
  {
    Node<S> *delNode = this->tail;
    S result;
    if (head == NULL)
    {
      cout << " Stack underflow " << endl;
      return result;
    }
    if (tail == head)
    {
      head = tail = NULL;
    }
    else
    {
      tail = delNode->prev;
      tail->next = NULL;
    }
    result = delNode->value;
    delete delNode;
    this->count--;
    return result;
  }
  // top
  S top()
  {
    S result;
    if (tail == NULL)
    {
      cout << "Stack Underflow | No element in the stack" << endl;
    }
    else
    {
      result = tail->value;
    }
    return result;
  }
  // size
  int size()
  {
    return this->count;
  }

  // empty
  bool empty()
  {
    if (head == NULL)
      return true;
    else
      return false;
  }
  // mid
  S mid()
  {
    S result;
    if (head == NULL)
    {
      cout << " Stack underflow " << endl;
      return result;
    }
    int middle = this->count / 2;
    Node<S> *temp = this->head;
    int midCount = 0;
    while (temp != NULL && midCount != middle)
    {
      temp = temp->next;
      midCount++;
    }
    result = temp->value;
    return result;
  }
};
